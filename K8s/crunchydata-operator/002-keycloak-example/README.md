# Keycloak

> [!WARNING]
> Make sure node has enough resources (CPU & Memory)

## Postgres init

[initial setup](../001-simple_postgres/README.md)

## Keycloak init

```bash
kubectl apply -f keycloak.yaml

kubectl apply -f keycloak-example-01/keycloak-service.yaml

kubectl port-forward -n postgres-operator service/keycloak --address localhost 8080:8080
```
