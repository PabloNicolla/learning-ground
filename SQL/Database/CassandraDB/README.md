# Cassandra

- [Cassandra](#cassandra)
  - [Introduction](#introduction)
  - [Architecture and Design](#architecture-and-design)
  - [Key Features](#key-features)
  - [Data Model](#data-model)
  - [Consistency Levels](#consistency-levels)
  - [Replication Strategies](#replication-strategies)
  - [Performance](#performance)
  - [Cassandra Query Language (CQL)](#cassandra-query-language-cql)
  - [Use Cases](#use-cases)
  - [Pros and Cons](#pros-and-cons)
  - [Popular Deployments](#popular-deployments)
  - [Cassandra vs. Other Databases](#cassandra-vs-other-databases)
  - [Cassandra Ecosystem](#cassandra-ecosystem)
  - [Summary](#summary)

## Introduction

Apache Cassandra is a highly scalable, distributed NoSQL database designed to handle large amounts of data across many commodity servers, providing high availability with no single point of failure. It is used by organizations requiring real-time big data storage and processing.

## Architecture and Design

- Distributed and Decentralized: Cassandra is a peer-to-peer database where each node (server) is equal, with no master-slave architecture. All nodes communicate with each other via a gossip protocol to share information about themselves and other nodes.
- Partitioning: Data is partitioned across all nodes using consistent hashing. Each node is responsible for a portion of the data, and partitions are assigned using tokens that divide the data space.
- Replication: Cassandra replicates data across multiple nodes to ensure fault tolerance. The replication factor determines how many copies of the data are stored. Nodes can be spread across multiple data centers for improved resilience and geographic redundancy.
- Fault Tolerance: Cassandra provides fault tolerance by replicating data across nodes. If one node fails, others can take over without data loss.
- Eventual Consistency: By default, Cassandra is eventually consistent, meaning that updates propagate through the system, and consistency is achieved over time. It allows trade-offs between consistency, availability, and partition tolerance (as per the CAP theorem).

## Key Features

- Scalability: Cassandra can scale horizontally by adding more nodes. There is no downtime when increasing capacity, and the database scales linearly.
- High Availability: The decentralized architecture ensures that there is no single point of failure. Data replication across nodes ensures that the system remains available, even during hardware or network failures.
- Flexible Data Model: Cassandra provides a wide-column data model. Data is stored in tables with rows and columns, but unlike relational databases, the schema for columns can vary between rows in a table, offering flexibility.
- Tunable Consistency: You can tune the consistency level for reads and writes on a per-query basis. For instance, you can specify whether a query should return results from a single replica or wait until multiple replicas confirm the result.
- Compaction and Bloom Filters: Cassandra uses a process called compaction to merge and organize data on disk, reducing storage overhead. Bloom filters are used to optimize queries by filtering out non-relevant rows quickly.
- Support for Distributed Queries: Cassandra has a query language called Cassandra Query Language (CQL) that provides an SQL-like syntax for interacting with the data.
- Write Optimized: Cassandra is optimized for high write throughput, often making it a go-to for write-heavy workloads.

## Data Model

- Keyspace: A keyspace is the top-level namespace in Cassandra. It defines how data replication is managed, the replication factor, and other configurations.
- Tables: Within a keyspace, data is organized into tables. Unlike relational databases, Cassandra tables are schema-free, meaning columns can vary between rows.
- Rows and Columns: Data in a table is stored in rows and columns, where each row is identified by a unique primary key. Cassandra rows are grouped into partitions, and each partition key determines the data’s distribution across nodes.
- Partition Key: This key is essential in Cassandra as it determines which node stores the data. Choosing the right partition key is crucial for performance.
- Clustering Columns: After the partition key, clustering columns define the sorting of the rows within the same partition.

## Consistency Levels

Cassandra allows you to define the level of consistency for both reads and writes:

- ANY: Guarantees the write will succeed once at least one replica has responded.
- ONE: The write/read is acknowledged when one replica responds.
- QUORUM: Requires a majority of replicas to respond (more than half).
- ALL: All replicas must respond for the write/read to be successful.
- LOCAL_QUORUM: Ensures that a quorum is achieved within a single data center.

## Replication Strategies

Cassandra supports two primary replication strategies:

- SimpleStrategy: Used for single data centers, it distributes replicas by moving clockwise around the ring.
- NetworkTopologyStrategy: This is for multi-data center setups. It allows you to specify how many replicas should go into each data center, enabling more granular control of availability.

## Performance

- Write-Optimized: Cassandra is designed to handle massive amounts of writes efficiently, primarily because it uses a Log-Structured Merge (LSM) tree for managing writes. Writes are first saved to a commit log for durability and then written to an in-memory table (MemTable) before being flushed to disk.
- Reads: While optimized for writes, Cassandra also provides fast reads through the use of Bloom filters, memtables, and SSTables (Sorted String Tables) on disk.

## Cassandra Query Language (CQL)

CQL is similar to SQL but is designed for Cassandra’s distributed architecture. While it supports many common SQL features like SELECT, INSERT, UPDATE, and DELETE, it lacks joins and subqueries because they don’t scale well in a distributed system. Key points:

- No support for JOIN or foreign keys.
- No complex queries like aggregations or GROUP BY (although materialized views and secondary indexes can help).

## Use Cases

- Real-Time Big Data: Organizations needing to store massive amounts of time-series data or sensor data, such as IoT applications.
- Content Management: High-traffic websites or media platforms where availability and scalability are critical.
- Recommendation Engines: E-commerce platforms and social media networks often use Cassandra to store user activity for recommendation engines.
- Messaging Systems: Applications requiring high write throughput, like messaging systems and event logs, leverage Cassandra’s distributed nature.

## Pros and Cons

| Pros                                                          | Cons                                                                         |
| ------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| Scalability: Easily scales horizontally.                      | Complex Queries: No support for joins or aggregations.                       |
| Fault Tolerance: No single point of failure.                  | Eventual Consistency: Strong consistency is not the default.                 |
| Tunable Consistency: Flexibility in read/write consistency.   | Operational Complexity: Requires expertise to manage and tune.               |
| High Write Performance: Optimized for high write throughput.  | Read Latency: Writes are fast, but reads can sometimes be slower.            |
| Geographical Distribution: Excellent for multi-region setups. | Limited Transactions: Only lightweight transactions with a single partition. |

## Popular Deployments

- Netflix: Uses Cassandra to manage huge amounts of metadata (e.g., what shows users watch, ratings).
- Instagram: Handles user posts, likes, and comments.
- Apple: Manages more than 10 petabytes of data across their cloud services.
- Uber: Leverages Cassandra for geospatial data.

## Cassandra vs. Other Databases

| Feature          | Cassandra                      | MongoDB                                             | HBase                       | RDBMS                             |
| ---------------- | ------------------------------ | --------------------------------------------------- | --------------------------- | --------------------------------- |
| Data Model       | Wide-column                    | Document-based                                      | Wide-column                 | Relational                        |
| Scalability      | Linear scalability             | Scalable, but not as efficient as Cassandra         | Scalable, but complex setup | Limited, vertical scaling         |
| Consistency      | Tunable, Eventual              | Strong and eventual consistency                     | Strong consistency          | Strong consistency                |
| Fault Tolerance  | No single point of failure     | Replication, but can have a single point of failure | No single point of failure  | Can have single points of failure |
| Query Complexity | Limited SQL-like queries (CQL) | Flexible JSON queries                               | Limited SQL-like queries    | Supports complex queries, joins   |

## Cassandra Ecosystem

- DataStax: Provides an enterprise version of Cassandra with additional tools and features for managing large Cassandra clusters.
- Apache Kafka: Often used in conjunction with Cassandra to handle streaming data.

## Summary

In summary, Apache Cassandra is a powerful solution for use cases that require high availability, fault tolerance, and scalability. It excels in handling large amounts of data with fast write speeds but may not be suitable for applications requiring complex query capabilities or transactional integrity across multiple partitions.
