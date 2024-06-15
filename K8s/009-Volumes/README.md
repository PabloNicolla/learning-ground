# Volumes

## ephemeral Volumes

are deleted with the pod, but are preserved across container restarts

### Volume Types that support ephemeral Volumes

- emptyDir
  - An empty Volume is created for the Pod as soon as it is scheduled on the worker node. The Volume's life is tightly coupled with the Pod. If the Pod is terminated, the content of emptyDir is deleted forever.
- hostPath
  - The hostPath Volume Type shares a directory between the host and the Pod. If the Pod is terminated, the content of the Volume is still available on the host.
- secret
  - The secret Volume Type facilitates the supply of sensitive information, such as passwords, certificates, keys, or tokens to Pods.
- configMap
  - The configMap objects facilitate the supply of configuration data, or shell commands and arguments into a Pod.
- persistentVolumeClaim
  - A PersistentVolume is consumed by a Pod using a persistentVolumeClaim.

## PersistentVolumes

- Memory allocation

## PersistentVolumeClaims

- Memory utilization

## Example

```
kubectl apply -f filename

kubectl expose deployment blue-app --type=NodePort
```
