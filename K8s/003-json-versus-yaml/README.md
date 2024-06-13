# json versus yaml

```
kubectl run nginx-pod --image=nginx:1.22.1 --port=80 \
--dry-run=client -o yaml > nginx-pod.yaml
```

The command above generates a definition manifest in YAML, but we can generate a JSON definition file just as easily with:

```
kubectl run nginx-pod --image=nginx:1.22.1 --port=80 \
--dry-run=client -o json > nginx-pod.json
```

Both the YAML and JSON definition files can serve as templates or can be loaded into the cluster respectively as such:

```
kubectl create -f nginx-pod.yaml
kubectl create -f nginx-pod.json
```

Useful commands

```
kubectl apply -f nginx-pod.yaml
kubectl get pods
kubectl get pod nginx-pod -o yaml
kubectl get pod nginx-pod -o json
kubectl describe pod nginx-pod
kubectl delete pod nginx-pod


kubectl scale rs frontend --replicas=4
```

Deployment object related commands

```
kubectl apply -f nginx-deploy.yaml --record
kubectl get deployments
kubectl get deploy -o wide
kubectl scale deploy nginx-deployment --replicas=4
kubectl get deploy nginx-deployment -o yaml
kubectl get deploy nginx-deployment -o json
kubectl describe deploy nginx-deployment
kubectl rollout status deploy nginx-deployment
kubectl rollout history deploy nginx-deployment
kubectl rollout history deploy nginx-deployment --revision=1
kubectl set image deploy nginx-deployment nginx=nginx:1.21.5 --record
kubectl rollout history deploy nginx-deployment --revision=2
kubectl rollout undo deploy nginx-deployment --to-revision=1
kubectl get all -l app=nginx -o wide
kubectl delete deploy nginx-deployment
kubectl get deploy,rs,po -l app=nginx
```