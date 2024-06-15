# ConfigMap & Secret

## ConfigMap

```
kubectl create configmap my-config \
  --from-literal=key1=value1 \
  --from-literal=key2=value2

kubectl create configmap permission-config \
  --from-file=<path/to/>permission-reset.properties
```

### Use

In the following example all the myapp-full-container Container's environment variables receive the values of the full-config-map ConfigMap keys:

```yaml
#...
containers:
  - name: myapp-full-container
    image: myapp
    envFrom:
      - configMapRef:
        name: full-config-map
#...
```

---

In the following example the myapp-specific-container Container's environment variables receive their values from specific key-value pairs from two separate ConfigMaps, config-map-1 and config-map-2 respectively:

```yaml
#...
containers:
  - name: myapp-specific-container
    image: myapp
    env:
      - name: SPECIFIC_ENV_VAR1
        valueFrom:
          configMapKeyRef:
            name: config-map-1
            key: SPECIFIC_DATA
      - name: SPECIFIC_ENV_VAR2
        valueFrom:
          configMapKeyRef:
            name: config-map-2
            key: SPECIFIC_INFO
#...
```

The SPECIFIC_ENV_VAR1 environment variable set to the value of SPECIFIC_DATA key from config-map-1 ConfigMap, and SPECIFIC_ENV_VAR2 environment variable set to the value of SPECIFIC_INFO key from config-map-2 ConfigMap.

---

Mount a vol-config-map ConfigMap as a Volume inside a Pod. The configMap Volume plugin converts the ConfigMap object into a mountable resource. For each key in the ConfigMap, a file gets created in the mount path (where the file is named with the key name) and the respective key's value becomes the content of the file

```yaml
# ...
containers:
  - name: myapp-vol-container
    image: myapp
    volumeMounts:
      - name: config-volume
        mountPath: /etc/config
volumes:
  - name: config-volume
    configMap:
      name: vol-config-map
# ...
```

### ConfigMap Example

```
kubectl create configmap green-web-cm --from-file=index.html

kubectl get cm

kubectl describe green-web-cm

kubectl apply -f web-green.yaml

kubectl expose deployment.apps/green-web --type=NodePort

minikube service green-web
```
