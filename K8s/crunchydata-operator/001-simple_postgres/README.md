# Simple postgres

## Create

```sh
# create
kubectl apply -k kustomize/postgres

# track progress
kubectl -n postgres-operator describe postgresclusters.postgres-operator.crunchydata.com hippo
```

```yaml
apiVersion: postgres-operator.crunchydata.com/v1beta1
kind: PostgresCluster
metadata:
  name: hippo # cluster name
spec:
  image: registry.developers.crunchydata.com/crunchydata/crunchy-postgres:ubi8-16.3-1
  postgresVersion: 16
  instances:
    - name: instance1
      dataVolumeClaimSpec: # If this is not defined, then the default storage class in your Kubernetes environment is used.
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: 1Gi
  backups:
    pgbackrest:
      image: registry.developers.crunchydata.com/crunchydata/crunchy-pgbackrest:ubi8-2.51-1
      repos:
        - name: repo1
          volume:
            volumeClaimSpec:
              accessModes:
                - "ReadWriteOnce"
              resources:
                requests:
                  storage: 1Gi
```

## Connect

### Services

```sh
kubectl -n postgres-operator get svc --selector=postgres-operator.crunchydata.com/cluster=hippo
```

```output
NAME              TYPE        CLUSTER-IP     EXTERNAL-IP   PORT(S)    AGE
hippo-ha          ClusterIP   10.103.73.92   <none>        5432/TCP   3h14m
hippo-ha-config   ClusterIP   None           <none>        <none>     3h14m
hippo-pods        ClusterIP   None           <none>        <none>     3h14m
hippo-primary     ClusterIP   None           <none>        5432/TCP   3h14m
hippo-replicas    ClusterIP   10.98.110.215  <none>        5432/TCP   3h14m
```

### Secret's information

When your Postgres cluster is initialized, PGO will create a Postgres user and other information in a secret called `<clusterName>-pguser-<userName>`.

- user
- password
- dbname
- host
  - The name of the host of the database. This references the Service of the primary Postgres instance.
- port
  - The port that the database is listening on.
- uri
  - A PostgreSQL connection URI that provides all the information for logging into the Postgres database.
- jdbc-uri

### Default service type

By default, PGO deploys Services with the ClusterIP Service type.

Selecting NodePort example:

```yaml
spec:
  service:
    metadata:
      annotations:
        my-annotation: value1
      labels:
        my-label: value2
    type: NodePort
    nodePort: 32000
```

### Connect Directly

If in the same network

```bash
psql $(kubectl -n postgres-operator get secrets hippo-pguser-hippo -o go-template='{{.data.uri | base64decode}}')
```

### Connect Using Port-Forward

```bash
# port forward (make sure host machine's port is available)
PG_CLUSTER_PRIMARY_POD=$(kubectl get pod -n postgres-operator -o name \
  -l postgres-operator.crunchydata.com/cluster=hippo,postgres-operator.crunchydata.com/role=master)
kubectl -n postgres-operator port-forward "${PG_CLUSTER_PRIMARY_POD}" 5444:5432

# connect to DB
PG_CLUSTER_USER_SECRET_NAME=hippo-pguser-hippo

PGPASSWORD=$(kubectl get secrets -n postgres-operator "${PG_CLUSTER_USER_SECRET_NAME}" -o go-template='{{.data.password | base64decode}}') \
PGUSER=$(kubectl get secrets -n postgres-operator "${PG_CLUSTER_USER_SECRET_NAME}" -o go-template='{{.data.user | base64decode}}') \
PGDATABASE=$(kubectl get secrets -n postgres-operator "${PG_CLUSTER_USER_SECRET_NAME}" -o go-template='{{.data.dbname | base64decode}}')

echo $PGPASSWORD

psql -h localhost -p 5444 -U $PGUSER -d $PGDATABASE
```

## Next step

[connect an application](../keycloak-example-01/README.md)
