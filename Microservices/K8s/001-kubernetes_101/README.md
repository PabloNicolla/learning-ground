# Kubernetes 101

[kubernetes_101](https://minikube.sigs.k8s.io/docs/tutorials/kubernetes_101/)

## Initial check

```
minikube version

minikube start
```

```
kubectl cluster-info

kubectl get nodes
```

## Deploy & proxy

```
kubectl create deployment kubernetes-bootcamp --image=gcr.io/google-samples/kubernetes-bootcamp:v1

kubectl get deployments
```

```
echo -e "Starting Proxy. After starting it will not output a response. Please return to your original terminal window\n"; kubectl proxy

curl http://localhost:8001/version
```

```
export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}')
echo Name of the Pod: $POD_NAME

curl http://localhost:8001/api/v1/namespaces/default/pods/$POD_NAME
```

## Explore app

```
kubectl get pods
```

### View the container logs

```
kubectl logs $POD_NAME
```

### Executing command on the container

```
kubectl exec $POD_NAME -- env

kubectl exec -ti $POD_NAME -- bash
```

```
cat server.js

curl localhost:8080
```

## Expose your app publicly

```
kubectl get pods

kubectl get services

kubectl expose deployment/kubernetes-bootcamp --type="NodePort" --port 8080

kubectl get services
```

> [!IMPORTANT]
> Note for **Docker Desktop users:** Due to Docker Desktop networking limitations, by default you’re unable to access pods directly from the host.
> Run `minikube service kubernetes-bootcamp`, this will create a SSH tunnel from the pod to your host and open a window in your default browser that’s connected to the service. Skip all commands until [next milestone](#using-labels)

```
kubectl describe services/kubernetes-bootcamp

export NODE_PORT=$(kubectl get services/kubernetes-bootcamp -o go-template='{{(index .spec.ports 0).nodePort}}')
echo NODE_PORT=$NODE_PORT
```

```
curl $(minikube ip):$NODE_PORT
```

## Using labels

```
kubectl describe deployment

kubectl get pods -l app=kubernetes-bootcamp

kubectl get services -l app=kubernetes-bootcamp

export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}')
echo Name of the Pod: $POD_NAME

kubectl label pods $POD_NAME version=v1

kubectl describe pods $POD_NAME

kubectl get pods -l version=v1
```

## Deleting a service

```
kubectl delete service -l app=kubernetes-bootcamp

kubectl get services

curl $(minikube ip):$NODE_PORT
```

## Scale up your app

```
kubectl expose deployment/kubernetes-bootcamp --type="NodePort" --port 8080

kubectl get deployments

kubectl get rs
```

```
kubectl scale deployments/kubernetes-bootcamp --replicas=4

kubectl get deployments

kubectl get pods -o wide

kubectl describe deployments/kubernetes-bootcamp
```

## Load Balancing

```
kubectl describe services/kubernetes-bootcamp

minikube service kubernetes-bootcamp
```

## Scale Down

```
kubectl scale deployments/kubernetes-bootcamp --replicas=2

kubectl get deployments

kubectl get pods -o wide
```

## Update your app

```
kubectl set image deployments/kubernetes-bootcamp kubernetes-bootcamp=jocatalin/kubernetes-bootcamp:v2

kubectl get pods
```

## Verify an update

```
kubectl describe services/kubernetes-bootcamp

kubectl rollout status deployments/kubernetes-bootcamp
```

## Rollback an update

```
kubectl set image deployments/kubernetes-bootcamp kubernetes-bootcamp=gcr.io/google-samples/kubernetes-bootcamp:v10

kubectl get deployments

kubectl get pods

kubectl rollout undo deployments/kubernetes-bootcamp

kubectl get deployments

kubectl get pods
```
