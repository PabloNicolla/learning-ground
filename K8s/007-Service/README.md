# Services

```
kubectl apply -f <filename>

minikube service --all
```

```
minikube ip

# ip + Service's NodePort

# OR

minikube service service-name

# OR

minikube service service-name --url

# OR

kubectl port-forward svc/service-name 8080:80

# OR (Minikube + Docker drive)

kubectl expose deployment deployment-name --name=web-lb --type=LoadBalancer --port=8080

minikube tunnel

kubectl get services
```
