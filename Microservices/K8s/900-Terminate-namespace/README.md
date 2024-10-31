# Terminate namespace

```bash
kubectl get ns <namespace_name> -o json >> ns.json

kubectl proxy

curl -k -H "Content-Type: application/json" -X PUT --data-binary ns.json http://127.0.0.1:8001/api/v1/namespaces/<namespace_name>/finalize
```
