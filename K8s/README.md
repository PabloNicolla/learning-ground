# K8s

## Minikube

```bash
# Check the Minikube version
minikube version

# Start a local Kubernetes cluster using Minikube
minikube start

# Expose a service to be accessible from the host machine
minikube service <service_name>

# Get the IP address of the Minikube cluster
minikube ip

# Create a network tunnel to access services with LoadBalancer type
minikube tunnel

# List all available Minikube addons
minikube addons list

# Enable a specific addon in Minikube
minikube addons enable <addon_name>
```

## Kubectl

```bash
# Common Kubernetes objects
objects = [ nodes           # ...
    | pods                  # Smallest building blocks of the Kubernetes system
    | deployments           # Manage the lifecycle of one or more identical Pods
    | replicaSets           # Ensure that a specified number of pod replicas are running at any given time
    | statefulSets          # Workload API object used to manage stateful applications
    | daemonSets            # Ensure that all (or some) nodes run a copy of a pod
    | namespaces            # ...
    | services              # An abstraction which defines a logical set of Pods and a policy by which to access them
    | jobs                  # Creates one or more Pods and ensures that a specified number of them successfully terminate
    | configMaps            # Decouple configuration artifacts from image content to keep containerized applications portable
    | secrets               # Store and manage sensitive information, such as passwords, OAuth tokens, and ssh keys
    | persistentVolumes     # A way for users to claim durable storage
    | ...]
```

```bash
# Get detailed information about a specific object type
kubectl get <objects> -l <label> -o <wide|yaml|json> -n <namespace_name>

# Display the version of kubectl and the Kubernetes cluster it connects to
kubectl version

# Show detailed information about a specific object
kubectl describe <object_type> <object_name> -n <namespace_name>

# Apply a configuration file to create or update resources in the cluster
kubectl apply -f <file_path>

# Delete a specific object from the cluster
kubectl delete <object_type> <object_name> -n <namespace_name>

# Forward one or more local ports to a pod
kubectl port-forward <svc/service-name> --address localhost <host_port>:<target_port>

# Display information about the Kubernetes cluster
kubectl cluster-info

# Manage the rollout of updates to deployments
kubectl rollout <command> <deployment_name> -n <namespace_name>

# Execute a command in a container
kubectl exec $POD_NAME -- env          # List environment variables in the specified pod
kubectl exec -ti $POD_NAME -- bash     # Start an interactive bash session in the specified pod

# Expose a Kubernetes service
kubectl expose <object_type> <object_name> --port=<port> --target-port=<target_port> -n <namespace_name>

# Get resource usage (CPU/Memory)
kubectl top nodes
kubectl top pods -n <namespace_name>

# Delete a namespace and all the resources in it
kubectl delete namespace <namespace_name>
```

---

```bash
# Get logs from a specific pod
kubectl logs <pod_name> -n <namespace_name>

# Follow logs from a specific pod
kubectl logs -f <pod_name> -n <namespace_name>

# Get events in the cluster
kubectl get events -n <namespace_name>

# Scale a deployment
kubectl scale deployment <deployment_name> --replicas=<number_of_replicas> -n <namespace_name>

# Edit a resource on the fly
kubectl edit <resource_type> <resource_name> -n <namespace_name>

# Get detailed information about the current context
kubectl config view

# Switch between different contexts
kubectl config use-context <context_name>

# Run a pod with a specified image
kubectl run <pod_name> --image=<image_name> --restart=Never -n <namespace_name>

# Attach to a running container
kubectl attach <pod_name> -c <container_name> -n <namespace_name>
```
