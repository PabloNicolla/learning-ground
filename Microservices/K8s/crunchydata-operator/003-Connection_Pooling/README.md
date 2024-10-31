# Connection Pooling

[PgBouncer Tutorial](https://www.youtube.com/watch?v=ddKm7a7xOpk)

## Add the following to postgres.yaml

```yaml
# ...
spec:
  proxy: # add this to spec.*
    pgBouncer:
      image: registry.developers.crunchydata.com/crunchydata/crunchy-pgbouncer:ubi8-1.22-1
# ...
```

PGO adds additional information to the user Secrets:

- pgbouncer-host
  - replaces host
- pgbouncer-port
  - replaces port
- pgbouncer-uri
  - replaces uri
- pgbouncer-jdbc-uri
  - replaces jdbc-uri

## For HA check options (Postgres LoadBalancing and/or replication)

[PgPool](https://www.youtube.com/watch?v=qpxKlH7DBjU)

or

[HAProxy](https://www.youtube.com/watch?v=a_lW1Hz-IPU)
