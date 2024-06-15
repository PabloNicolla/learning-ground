# StatefulSets

The StatefulSet controller is used for stateful applications which require a unique identity, such as name, network identifications, or strict ordering, such as a MySQL cluster.

The StatefulSet controller provides identity and guaranteed ordering of deployment and scaling to Pods. However, the StatefulSet controller has very strict Service and Storage Volume dependencies that make it challenging to configure and deploy. It also supports scaling, rolling updates, and rollbacks.
