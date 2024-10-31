# Postgres Operator - CrunchyData

## install cluster-wide

```bash
# after forking repository
git clone --depth 1 "git@github.com:PabloNicolla/postgres-operator-examples.git"
cd postgres-operator-examples

# install PGO
kubectl apply -k kustomize/install/namespace
kubectl apply --server-side -k kustomize/install/default

# check
kubectl -n postgres-operator get pods \
  --selector=postgres-operator.crunchydata.com/control-plane=postgres-operator \
  --field-selector=status.phase=Running
```

## delete cluster-wide

```sh
kubectl delete -k kustomize/install/default

kubectl delete -k kustomize/install/namespace
```
