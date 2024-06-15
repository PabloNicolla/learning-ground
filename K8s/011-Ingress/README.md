# Ingress

The Ingress API resource, which represents another layer of abstraction, deployed in front of the Service API resources, offering a unified method of managing access to applications from the external world.

Ingress resource - a collection of rules that manage inbound connections to cluster Services.

## Ingress Controller

In order to ensure that the ingress controller is watching its corresponding ingress resource, the ingress resource definition manifest needs to include an ingress class name, such as spec.ingressClassName: nginx and optionally one or several annotations specific to the desired controller, such as nginx.ingress.kubernetes.io/service-upstream: "true" (for an nginx ingress controller).

Starting the Ingress Controller in Minikube is extremely simple. Minikube ships with the Nginx Ingress Controller set up as an addon, disabled by default. It can be easily enabled by running the following command:

```
minikube addons enable ingress

# run "minikube tunnel" and your ingress resources would be available at "127.0.0.1"
```

Once the Ingress Controller is deployed, we can create an Ingress resource

## Example

```
kubectl apply -f configMaps.yaml

kubectl apply -f web-blue.yaml

kubectl apply -f web-green.yaml

minikube addons enable ingress

minikube tunnel

# update etc/hosts
```
