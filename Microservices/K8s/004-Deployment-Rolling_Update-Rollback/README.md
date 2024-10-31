# Deployment Rolling Update and Rollback

## Create deployment yaml file

```
kubectl create deployment nginx-deployment \
--image=nginx:1.20.2 --port=80 --replicas=3 \
--dry-run=client -o yaml > nginx-deploy.yaml
```

## Rolling update

```
kubectl apply -f nginx-deploy.yaml

# get deployment, replicaSet, and pod from objects within the cluster that share label app=nginx-deployment
kubectl get deploy,rs,po -l app=nginx-deployment

# Scale up (scaling up/down does not change the rollout revision history)
kubectl scale deployment nginx-deployment --replicas=5

# current state
kubectl describe deployment/nginx-deployment

# get rollout history (3 different syntax accomplish the same task)
kubectl rollout history deploy nginx-deployment
kubectl rollout history deployment/nginx-deployment
kubectl rollout history deployment nginx-deployment

# change nginx image version
# Manually modify the deployment yaml file from "- image: nginx:1.20.2" to "- image: nginx:latest" 
# update deployment
kubectl apply -f nginx-deploy.yaml

# get rollout history
kubectl rollout history deployment nginx-deployment

# get details about the rollout history
kubectl rollout history deployment nginx-deployment --revision=1
kubectl rollout history deployment nginx-deployment --revision=2
```

## Rollback

```
# This will transform "revision 1" into "revision 3"
kubectl rollout undo deployment nginx-deployment --to-revision=1


kubectl rollout history deployment nginx-deployment

kubectl get deploy,rs,po -l app=nginx-deployment
```
