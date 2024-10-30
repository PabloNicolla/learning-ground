docker exec -it kafka-SD `
    kafka-topics `
    --create `
    --topic test-topic `
    --bootstrap-server localhost:9092 `
    --partitions 1 `
    --replication-factor 1
