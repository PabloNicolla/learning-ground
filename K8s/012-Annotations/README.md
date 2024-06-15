# Annotations

Annotations allow us to attach arbitrary non-identifying metadata to any objects, in a key-value format:

```json
"annotations": {
    "key1": "value1",
    "key2": "value2"
}
```

Unlike Labels, annotations are not used to identify and select objects. Annotations can be used to:

- Store build/release IDs, PR numbers, git branch, etc.
- Phone/pager numbers of people responsible, or directory entries specifying where such information can be found.
- Pointers to logging, monitoring, analytics, audit repositories, debugging tools, etc.
- Ingress controller information.
- Deployment state and revision information.
