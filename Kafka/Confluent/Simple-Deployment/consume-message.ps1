docker exec -it kafka-SD `
    kafka-console-consumer `
    --topic test-topic `
    --bootstrap-server localhost:9092 `
    --from-beginning
