# Redis

- [Redis](#redis)
  - [Introduction](#introduction)
    - [Redis: An In-Depth Overview with TypeScript](#redis-an-in-depth-overview-with-typescript)
      - [Key Features of Redis](#key-features-of-redis)
    - [Getting Started with Redis and TypeScript](#getting-started-with-redis-and-typescript)
      - [Installation](#installation)
    - [Setting Up Redis with TypeScript](#setting-up-redis-with-typescript)
    - [1. **Basic Operations (CRUD)**](#1-basic-operations-crud)
      - [Strings](#strings)
      - [Integers](#integers)
      - [Expiration](#expiration)
    - [2. **Complex Data Structures**](#2-complex-data-structures)
      - [Hashes](#hashes)
      - [Lists](#lists)
      - [Sets](#sets)
      - [Sorted Sets](#sorted-sets)
    - [3. **Publish/Subscribe (Pub/Sub)**](#3-publishsubscribe-pubsub)
    - [4. **Transactions**](#4-transactions)
    - [5. **Lua Scripting**](#5-lua-scripting)
    - [6. **Persistence**](#6-persistence)
    - [7. **Clustering**](#7-clustering)
    - [8. **Error Handling and Reconnection**](#8-error-handling-and-reconnection)
    - [9. **Best Practices**](#9-best-practices)
    - [Conclusion](#conclusion)

## Introduction

### Redis: An In-Depth Overview with TypeScript

Redis (Remote Dictionary Server) is an open-source, in-memory data structure store primarily used as a database, cache, and message broker. It supports a wide range of data structures like strings, hashes, lists, sets, sorted sets, bitmaps, hyperloglogs, and geospatial indexes. Redis is known for its speed and is often used in scenarios requiring low-latency data access.

#### Key Features of Redis

1. **In-Memory Storage**: Redis stores data in memory, providing extremely fast read and write operations.
2. **Data Persistence**: Though in-memory, Redis supports persistence via snapshotting (RDB) and append-only file (AOF) modes.
3. **Data Structures**: Supports multiple data structures, including strings, hashes, lists, sets, sorted sets, streams, etc.
4. **Pub/Sub Messaging**: Provides publish/subscribe functionality for message broadcasting.
5. **Replication**: Supports master-slave replication for high availability.
6. **Clustering**: Redis Cluster enables sharding across multiple nodes for scalability.
7. **Transactions**: Supports transactions using commands like `MULTI`, `EXEC`, and `WATCH`.
8. **Scripting**: Allows Lua scripting for atomic operations.

### Getting Started with Redis and TypeScript

To use Redis with TypeScript, you typically utilize the `ioredis` or `redis` package from npm. Here, we will use **ioredis** for its robust features and support for both standalone and clustered Redis environments.

#### Installation

```bash
npm install ioredis @types/ioredis
```

### Setting Up Redis with TypeScript

```typescript
import Redis from 'ioredis';

// Initialize Redis client
const redis = new Redis({
  host: '127.0.0.1',
  port: 6379,
  password: 'yourpassword', // If authentication is enabled
});

redis.on('connect', () => console.log('Redis connected'));
redis.on('error', (err) => console.error('Redis connection error:', err));
```

### 1. **Basic Operations (CRUD)**

#### Strings

```typescript
// Set a value
await redis.set('key', 'value');

// Get a value
const value = await redis.get('key');
console.log(value); // Output: 'value'

// Set with expiration (in seconds)
await redis.set('tempKey', 'tempValue', 'EX', 10);
```

#### Integers

```typescript
// Increment a value
await redis.set('counter', '0');
await redis.incr('counter'); // counter = 1
await redis.incrby('counter', 10); // counter = 11

// Decrement a value
await redis.decr('counter'); // counter = 10
```

#### Expiration

```typescript
// Set expiration time (in seconds)
await redis.expire('key', 60); // Expires in 60 seconds

// Check time to live (TTL)
const ttl = await redis.ttl('key');
console.log(ttl); // Output: remaining time in seconds
```

### 2. **Complex Data Structures**

#### Hashes

Used for storing objects or dictionaries.

```typescript
// Set hash values
await redis.hset('user:1000', 'name', 'Alice', 'age', '30');

// Get a specific field
const name = await redis.hget('user:1000', 'name');

// Get all fields and values
const user = await redis.hgetall('user:1000');
console.log(user); // Output: { name: 'Alice', age: '30' }
```

#### Lists

Used for implementing queues or message lists.

```typescript
// Push elements to a list
await redis.lpush('tasks', 'Task 1');
await redis.rpush('tasks', 'Task 2');

// Pop element from list
const task = await redis.lpop('tasks');
console.log(task); // Output: 'Task 1'

// Get list length
const length = await redis.llen('tasks');
console.log(length); // Output: 1
```

#### Sets

Used for storing unique values.

```typescript
// Add elements to a set
await redis.sadd('tags', 'nodejs', 'typescript', 'redis');

// Check membership
const isMember = await redis.sismember('tags', 'nodejs');
console.log(isMember); // Output: 1 (true)

// Get all members
const members = await redis.smembers('tags');
console.log(members); // Output: ['nodejs', 'typescript', 'redis']
```

#### Sorted Sets

Used for leaderboard or ranking systems.

```typescript
// Add elements with scores
await redis.zadd('leaderboard', 100, 'Alice', 200, 'Bob');

// Get rank of a member
const rank = await redis.zrevrank('leaderboard', 'Alice');
console.log(rank); // Output: 1

// Get top elements
const topPlayers = await redis.zrevrange('leaderboard', 0, -1);
console.log(topPlayers); // Output: ['Bob', 'Alice']
```

### 3. **Publish/Subscribe (Pub/Sub)**

Redis can be used for real-time messaging via Pub/Sub.

```typescript
// Publisher
const publisher = new Redis();
await publisher.publish('channel', 'Hello, Redis!');

// Subscriber
const subscriber = new Redis();
subscriber.subscribe('channel', (err) => {
  if (err) console.error('Subscription error:', err);
});

subscriber.on('message', (channel, message) => {
  console.log(`Received message from ${channel}: ${message}`);
});
```

### 4. **Transactions**

```typescript
await redis
  .multi()
  .set('key1', 'value1')
  .set('key2', 'value2')
  .exec((err, results) => {
    if (err) console.error('Transaction error:', err);
    console.log(results);
  });
```

### 5. **Lua Scripting**

Using Lua scripts for atomic operations.

```typescript
const script = `
  local current = redis.call('GET', KEYS[1])
  if current then
    redis.call('INCRBY', KEYS[1], ARGV[1])
  else
    redis.call('SET', KEYS[1], ARGV[1])
  end
  return redis.call('GET', KEYS[1])
`;

const result = await redis.eval(script, 1, 'counter', 10);
console.log(result); // Updated counter value
```

### 6. **Persistence**

Redis offers two main persistence options:

1. **RDB (Snapshotting)**: Saves the dataset as a snapshot to disk at specified intervals.
   - Config in `redis.conf`: `save 900 1` (every 15 mins if at least 1 key changed).
2. **AOF (Append-Only File)**: Logs every write operation.
   - Config in `redis.conf`: `appendonly yes`.

### 7. **Clustering**

Redis Cluster provides sharding capabilities. It splits the data into 16,384 hash slots across nodes.

Configuration involves setting up nodes with a `redis.conf` file specifying:

```conf
cluster-enabled yes
cluster-config-file nodes.conf
cluster-node-timeout 5000
```

**Connecting to a Cluster with ioredis:**

```typescript
const cluster = new Redis.Cluster([
  { host: '127.0.0.1', port: 7000 },
  { host: '127.0.0.1', port: 7001 },
  { host: '127.0.0.1', port: 7002 },
]);
```

### 8. **Error Handling and Reconnection**

Handling errors is critical in production:

```typescript
redis.on('error', (error) => {
  console.error('Redis Error:', error);
});

redis.on('reconnecting', () => {
  console.log('Reconnecting to Redis...');
});
```

### 9. **Best Practices**

- Use **Redis Clustering** or **Sharding** for large datasets.
- Implement **persistence** for critical data.
- Leverage **TTL** for caching scenarios to automatically clear expired data.
- Use **Lua scripting** for atomic multi-step operations.
- Monitor Redis metrics using **Prometheus** or **Redis Sentinel** for high availability.

### Conclusion

Redis is a powerful, versatile in-memory data store with a wide range of use cases, from caching and session management to real-time analytics and messaging. When combined with TypeScript, it allows developers to create type-safe, reliable, and scalable solutions.
