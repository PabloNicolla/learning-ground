docker exec -it kafka-SD `
    kafka-console-producer `
    --topic "test-topic" `
    --bootstrap-server localhost:9092
