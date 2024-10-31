# Liveness probe

```
kubectl apply -f yaml.file

kubectl get pod pod-name -w

kubectl describe pod pod-name
```

## check by using HTTP GET request

```yaml
# pod declaration
#...
livenessProbe:
  httpGet:
    path: /healthz
    port: 8080
    httpHeaders:
      - name: X-Custom-Header
        value: Awesome
  initialDelaySeconds: 15
  periodSeconds: 5
#...
# declaration continues
```

## TCP Liveness Probe

```yaml
# pod declaration
#...
livenessProbe:
  tcpSocket:
    port: 8080
  initialDelaySeconds: 15
  periodSeconds: 5
#...
# declaration continues
```

## gRPC Readiness Probe

```yaml
# pod declaration
#...
livenessProbe:
  grpc:
    port: 2379
  initialDelaySeconds: 10
#...
# declaration continues
```

## Readiness Probes

```yaml
# pod declaration
#...
readinessProbe:
  exec:
    command:
      - cat
      - /tmp/healthy
  initialDelaySeconds: 5
  periodSeconds: 5
#...
# declaration continues
```
