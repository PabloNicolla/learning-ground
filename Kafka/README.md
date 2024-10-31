# Apache Kafka

- [Apache Kafka](#apache-kafka)
  - [Introduction to Apache Kafka](#introduction-to-apache-kafka)
  - [Core Concepts](#core-concepts)
  - [Kafka Architecture](#kafka-architecture)
  - [Key Features](#key-features)
  - [Kafka Use Cases](#kafka-use-cases)
  - [Kafka Ecosystem](#kafka-ecosystem)
  - [Performance Characteristics](#performance-characteristics)
  - [Kafka Workflow](#kafka-workflow)
  - [Message Delivery Guarantees](#message-delivery-guarantees)
  - [Kafka and Other Messaging Systems](#kafka-and-other-messaging-systems)
  - [Managing Kafka](#managing-kafka)
  - [Kafka’s Future](#kafkas-future)
  - [Useful Tools \& Links](#useful-tools--links)

## Introduction to Apache Kafka

Apache Kafka is an open-source distributed event streaming platform used for building real-time data pipelines and streaming applications. Originally developed by LinkedIn, Kafka was open-sourced in 2011 and is now maintained by the Apache Software Foundation.

Kafka is designed to handle large-scale, high-throughput, and low-latency data streams, making it ideal for applications where real-time analytics, monitoring, and log aggregation are required.

## Core Concepts

- Producers: Applications that publish data (events or messages) to Kafka topics.
- Consumers: Applications that subscribe to topics to read messages.
- Topics: Categories or feeds to which producers publish messages, and from which consumers read messages.
- Partitions: Kafka topics are divided into partitions to enable parallelism and scalability. Each partition is an ordered, immutable sequence of messages.
- Brokers: Kafka runs in a cluster of servers, and each server is called a broker. Brokers manage the persistence and replication of messages in topics.
- Zookeeper: Used for managing and coordinating Kafka brokers in the cluster. (Note: Kafka now has its own consensus layer called KRaft, meant to replace Zookeeper.)

## Kafka Architecture

- Cluster: Kafka runs as a distributed system consisting of multiple brokers. Each broker is responsible for storing one or more partitions for topics.
- Replication: Kafka replicates partitions across multiple brokers to ensure fault tolerance and high availability. A leader is elected for each partition, and followers replicate the data from the leader.
- Log Storage: Each partition in Kafka is a log, where each message is stored with an offset (a unique identifier). This log is persistent and allows Kafka to store massive volumes of data.
- Offset: The position of a message within a partition. Consumers use offsets to track their position in the log, enabling fault-tolerant and scalable consumption of messages.

## Key Features

- High Throughput and Low Latency: Kafka can handle millions of messages per second with low latency, even under high load.
- Horizontal Scalability: Kafka can scale horizontally by adding more brokers to the cluster.
- Durability: Messages are persisted to disk and replicated across multiple brokers to ensure durability and reliability.
- Fault Tolerance: If a broker fails, partitions are reassigned to ensure continued operation.
- Retention Policies: Kafka supports time-based and size-based retention policies. Messages can be retained indefinitely, deleted after a certain time, or when the log reaches a certain size.

## Kafka Use Cases

- Real-time Streaming Analytics: Kafka is commonly used for real-time analytics pipelines, where large amounts of data need to be processed and analyzed in real time.
- Log Aggregation: Kafka can be used to collect and aggregate logs from different systems into a central platform for monitoring, analysis, and troubleshooting.
- Event Sourcing: Kafka is often used in event-driven architectures to handle the streaming of events that can trigger actions in multiple services.
- Data Integration: Kafka can be used to integrate disparate systems by streaming data between them in real-time.
- Messaging: Kafka can function as a highly scalable and fault-tolerant message queue, handling both real-time and batch processing.

## Kafka Ecosystem

- Kafka Connect: A framework for integrating Kafka with external systems such as databases, message queues, and file systems. It provides both source connectors (to import data into Kafka) and sink connectors (to export data from Kafka).
- Kafka Streams: A lightweight library built on top of Kafka that enables the building of stateful and stateless streaming applications. Kafka Streams processes data directly from Kafka topics and can perform tasks like filtering, mapping, and aggregating data.
- KSQL: A SQL-like interface for stream processing on top of Kafka Streams. KSQL allows for the creation of streaming applications using SQL queries.

## Performance Characteristics

Kafka is designed to be fast, scalable, and durable:

- Throughput: Kafka can process large volumes of data with minimal overhead. Its design leverages sequential disk I/O, which is more efficient than random disk access.
- Latency: Kafka is optimized for low-latency message delivery, especially in environments where real-time processing is critical.
- Fault Tolerance: Kafka achieves high availability through partition replication and leader election.
- Scalability: Kafka can scale by adding more partitions, consumers, or brokers to a cluster.

## Kafka Workflow

- Producer publishes messages: Producers publish messages to specific Kafka topics.
- Messages are partitioned: Kafka assigns each message to a partition (either based on a key or in a round-robin manner).
- Messages are stored: Kafka brokers store messages in the respective partitions, ensuring they are replicated across multiple brokers if replication is configured.
- Consumer subscribes to topics: Consumers can subscribe to one or more topics and process messages from them.
- Offsets are tracked: Each consumer maintains its position in the log via offsets, enabling exactly-once, at-least-once, or at-most-once message delivery semantics.

## Message Delivery Guarantees

- At-most-once: Messages are delivered to consumers, but if the consumer fails, there is no retry.
- At-least-once: Consumers receive messages, and if they fail, they can read them again from Kafka.
- Exactly-once: Ensures that each message is processed only once, even in failure scenarios. This is important for financial transactions or systems that require precise data processing.

## Kafka and Other Messaging Systems

- Kafka vs RabbitMQ: RabbitMQ is a traditional message broker with complex routing and queuing features. Kafka is more focused on high-throughput and fault-tolerant streaming, with a simpler design.
- Kafka vs ActiveMQ: ActiveMQ supports more advanced message queuing, but Kafka is more optimized for real-time event streaming and distributed data pipelines.
- Kafka vs AWS Kinesis: Both Kafka and Kinesis are designed for real-time streaming, but Kafka offers more control and flexibility with deployment, while Kinesis is fully managed by AWS and easier to use in that ecosystem.

## Managing Kafka

- Monitoring: Kafka exposes metrics via JMX, which can be monitored using tools like Prometheus and Grafana.
- Scaling Kafka: You can scale Kafka by adding more brokers, partitions, or consumers. Kafka automatically balances load across available resources.
- Security: Kafka supports authentication and authorization using SASL and SSL, allowing encrypted communication and role-based access control (RBAC).

## Kafka’s Future

Kafka continues to evolve, with a strong focus on improving scalability, durability, and ease of use. The introduction of KRaft mode (Kafka Raft), which removes the dependency on Zookeeper, is a major step forward in simplifying Kafka’s architecture.
Conclusion

Apache Kafka is a robust, scalable platform for handling high-throughput real-time data streams. Its versatile architecture, fault-tolerant design, and wide array of integrations make it an essential tool for modern data pipelines and event-driven systems.

## Useful Tools & Links

> [!IMPORTANT]
> For Windows, download the binary kafka. Source Download will not work.

- [Kafka](https://kafka.apache.org/)
- [offset explorer](https://offsetexplorer.com/)
- [confluence](https://www.confluent.io/)
