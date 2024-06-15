# ConfigMap & Secret

## ConfigMap

```
kubectl create configmap my-config \
  --from-literal=key1=value1 \
  --from-literal=key2=value2

# from file

kubectl create configmap permission-config \
  --from-file=<path/to/>permission-reset.properties
```

### ConfigMap: full import

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

### ConfigMap: partial import & Multiple configMaps

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

### ConfigMap: import as volume

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

kubectl describe cm green-web-cm

kubectl apply -f web-green.yaml

kubectl expose deployment.apps/green-web --type=NodePort

minikube service green-web
```

## Secret

It is important to keep in mind that by default, the Secret data is stored as plain text inside etcd, therefore administrators must limit access to the API server and etcd. However, Secret data can be encrypted at rest while it is stored in etcd, but this feature needs to be enabled at the API server level by the Kubernetes cluster administrator.

```
kubectl create secret generic my-password \
  --from-literal=password=mysqlpassword

```

### Secret: data

```
echo mysqlpassword | base64

bXlzcWxwYXNzd29yZAo=
```

```yaml
apiVersion: v1
kind: Secret
metadata:
  name: my-password
type: Opaque
data:
  password: bXlzcWxwYXNzd29yZAo=
```

note that base64 encoding does not mean encryption, and anyone can easily decode our encoded data:

```
echo "bXlzcWxwYXNzd29yZAo=" | base64 --decode

mysqlpassword
```

Therefore, make sure you do not commit a Secret's definition file in the source code.

### Secret: stringData

With stringData maps, there is no need to encode the value of each sensitive information field. The value of the sensitive field will be encoded when the my-password Secret is created:

```yaml
apiVersion: v1
kind: Secret
metadata:
  name: my-password
type: Opaque
stringData:
  password: mysqlpassword
```

### Secret: from file

```bash
echo mysqlpassword | base64

# bXlzcWxwYXNzd29yZAo=

echo -n 'bXlzcWxwYXNzd29yZAo=' > password.txt

# Now we can create the Secret from the password.txt file:

kubectl create secret generic my-file-password \
  --from-file=password.txt
```

### Secret: import

```yaml
# ....
spec:
  containers:
    - image: wordpress:4.7.3-apache
      name: wordpress
      env:
        - name: WORDPRESS_DB_PASSWORD
          valueFrom:
            secretKeyRef:
              name: my-password
              key: password
# ....
```

### Secret: import as volume

The following example creates a file for each my-password Secret key (where the files are named after the names of the keys), the files containing the values of the respective Secret keys:

```yaml
# ....
spec:
  containers:
    - image: wordpress:4.7.3-apache
      name: wordpress
      volumeMounts:
        - name: secret-volume
          mountPath: "/etc/secret-data"
          readOnly: true
  volumes:
    - name: secret-volume
      secret:
        secretName: my-password
# ....
```
