# Quota and Limits

types of quotas per Namespace:

- Compute Resource Quota
  - Limit the total sum of compute resources (CPU, memory, etc.) that can be requested in a given Namespace.
- Storage Resource Quota
  - Limit the total sum of storage resources (PersistentVolumeClaims, requests.storage, etc.) that can be requested.
- Object Count Quota
  - Restrict the number of objects of a given type (Pods, ConfigMaps, PersistentVolumeClaims, ReplicationControllers, Services, Secrets, etc.).

```yaml
apiVersion: v1
kind: ResourceQuota
metadata:
  name: compute-resources
  namespace: myspace
spec:
  hard:
    requests.cpu: "1"
    requests.memory: 1Gi
    limits.cpu: "2"
    limits.memory: 2Gi
    requests.nvidia.com/gpu: 4:
```

```yaml
apiVersion: v1
kind: ResourceQuota
metadata:
  name: object-counts
  namespace: myspace
spec:
  hard:
    configmaps: "10"
    persistentvolumeclaims: "4"
    pods: "4"
    secrets: "10"
    services: "10"
    services.loadbalancers: "2"
```

An additional resource that helps limit resource allocation to pods and containers in a namespace, is the LimitRange, used in conjunction with the ResourceQuota API resource. A LimitRange can:

- Set compute resources usage limits per Pod or Container in a namespace.
- Set storage request limits per PersistentVolumeClaim in a namespace.
- Set a request to limit ratio for a resource in a namespace.
- Set default requests and limits and automatically inject them into Containers' environments at runtime

```yaml
apiVersion: v1
kind: LimitRange
metadata:
  name: cpu-constraint-per-container
  namespace: myspace
spec:
  limits:
    - default: # default limits
        cpu: 500m
      defaultRequest: # default requests
        cpu: 500m
      max: # max defines the highest value of the range
        cpu: "1"
      min: # min defines the lowest value of the range
        cpu: 100m
      type: Container
```

> [!IMPORTANT]
> All the above are acting on the `myspace` namespace
