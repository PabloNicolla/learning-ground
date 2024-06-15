# Autoscaling

Autoscaling periodically adjust the number of running objects based on single, multiple, or custom metrics. Autoscalers available can be implemented individually or combined.

- Horizontal Pod Autoscaler (HPA)
  - HPA is an algorithm-based controller API resource which automatically adjusts the number of replicas in a ReplicaSet, Deployment, or Replication Controller based on CPU utilization.
- Vertical Pod Autoscaler (VPA)
  - VPA automatically sets Container resource requirements (CPU and memory) in a Pod and dynamically adjusts them at runtime, based on historical utilization data, current resource availability and real-time events. It is installed as a Custom Resource.
- Cluster Autoscaler
  - Cluster Autoscaler automatically re-sizes the Kubernetes cluster when there are insufficient resources available for new Pods expecting to be scheduled or when there are underutilized nodes in the cluster.
