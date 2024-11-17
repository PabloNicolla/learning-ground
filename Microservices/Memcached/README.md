# Memcached

- [Memcached](#memcached)
  - [Introduction](#introduction)
    - [Overview of Memcached](#overview-of-memcached)
      - [Key Features of Memcached](#key-features-of-memcached)
      - [Use Cases](#use-cases)
    - [How Memcached Works](#how-memcached-works)
    - [Setting Up Memcached](#setting-up-memcached)
      - [Installation](#installation)
      - [TypeScript Integration](#typescript-integration)
    - [TypeScript Example with `memcached` Library](#typescript-example-with-memcached-library)
      - [1. Basic Setup](#1-basic-setup)
      - [2. Using Promises with TypeScript](#2-using-promises-with-typescript)
      - [3. Error Handling and Fallback Mechanism](#3-error-handling-and-fallback-mechanism)
    - [Memcached Commands and Operations](#memcached-commands-and-operations)
    - [Monitoring Memcached](#monitoring-memcached)
    - [Best Practices](#best-practices)
    - [Conclusion](#conclusion)

## Introduction

### Overview of Memcached

**Memcached** is an open-source, high-performance, distributed memory object caching system. It is used to speed up dynamic web applications by reducing database load through caching data in RAM. It's a simple yet powerful tool for managing a key-value store for short-term data storage.

#### Key Features of Memcached

1. **In-Memory Storage**: Stores data in RAM, providing very fast access.
2. **Distributed**: Can be scaled horizontally across multiple nodes to manage large datasets.
3. **Key-Value Store**: Supports simple key-value pairs, making it easy to use.
4. **Eviction Policy**: Uses LRU (Least Recently Used) eviction policy to manage memory.
5. **No Persistence**: Memcached does not store data on disk; it is purely an in-memory cache.

#### Use Cases

- **Database Caching**: Reduce load on a database by caching frequently accessed data.
- **Session Storage**: Store session data for web applications.
- **Content Caching**: Cache API responses or HTML content to improve website performance.
- **Rate Limiting**: Track API usage and limit request rates.

### How Memcached Works

1. **Client Request**: The client sends a key-value pair request to the Memcached server.
2. **Data Retrieval**: Memcached checks if the data is present in its memory:
   - If **present**, it returns the data to the client (cache hit).
   - If **absent**, the client must retrieve the data from the original source (cache miss), then store it in Memcached.
3. **Key Expiration**: Each key can have an optional expiration time. When the time elapses, the key is evicted.
4. **LRU Eviction**: If the memory is full, Memcached removes the least recently used keys.

### Setting Up Memcached

#### Installation

For Linux:

```bash
sudo apt update
sudo apt install memcached libmemcached-tools
```

To start and enable Memcached:

```bash
sudo systemctl start memcached
sudo systemctl enable memcached
```

To check if it's running:

```bash
sudo systemctl status memcached
```

#### TypeScript Integration

To interact with Memcached in a TypeScript project, you can use the `memjs` or `memcached` npm package.

Install the package:

```bash
npm install memcached @types/memcached
```

### TypeScript Example with `memcached` Library

#### 1. Basic Setup

```typescript
import Memcached from 'memcached';

const memcached = new Memcached('localhost:11211');

const key = 'user:123';
const value = JSON.stringify({ id: 123, name: 'Alice', age: 25 });
const ttl = 3600; // 1 hour in seconds

// Setting a key
memcached.set(key, value, ttl, (err) => {
  if (err) {
    console.error('Error setting key:', err);
    return;
  }
  console.log('Key set successfully');
});

// Getting a key
memcached.get(key, (err, data) => {
  if (err) {
    console.error('Error getting key:', err);
    return;
  }
  console.log('Data retrieved:', JSON.parse(data as string));
});

// Deleting a key
memcached.del(key, (err) => {
  if (err) {
    console.error('Error deleting key:', err);
    return;
  }
  console.log('Key deleted successfully');
});
```

#### 2. Using Promises with TypeScript

To make working with Memcached more TypeScript-friendly, we can create a wrapper with Promises:

```typescript
import Memcached from 'memcached';

const memcached = new Memcached('localhost:11211');

class MemcachedClient {
  set(key: string, value: any, ttl: number): Promise<void> {
    return new Promise((resolve, reject) => {
      memcached.set(key, JSON.stringify(value), ttl, (err) => {
        if (err) reject(err);
        else resolve();
      });
    });
  }

  get<T>(key: string): Promise<T | null> {
    return new Promise((resolve, reject) => {
      memcached.get(key, (err, data) => {
        if (err) reject(err);
        else resolve(data ? JSON.parse(data) : null);
      });
    });
  }

  delete(key: string): Promise<void> {
    return new Promise((resolve, reject) => {
      memcached.del(key, (err) => {
        if (err) reject(err);
        else resolve();
      });
    });
  }
}

// Usage
(async () => {
  const client = new MemcachedClient();

  await client.set('greeting', { message: 'Hello World' }, 3600);
  const data = await client.get<{ message: string }>('greeting');
  console.log(data); // Output: { message: 'Hello World' }

  await client.delete('greeting');
})();
```

#### 3. Error Handling and Fallback Mechanism

When working with Memcached, it's essential to implement error handling and fallback mechanisms for cache misses.

```typescript
async function getUserData(userId: number): Promise<{ id: number; name: string }> {
  const key = `user:${userId}`;
  const client = new MemcachedClient();

  try {
    // Try to get data from Memcached
    const cachedData = await client.get<{ id: number; name: string }>(key);
    if (cachedData) return cachedData;

    // If not found in cache, fallback to fetching from database (mocked here)
    const userData = { id: userId, name: `User${userId}` }; // Assume this comes from a DB
    await client.set(key, userData, 600); // Cache for 10 minutes
    return userData;
  } catch (error) {
    console.error('Memcached error:', error);
    // If Memcached fails, proceed with fetching from database
    return { id: userId, name: `User${userId}` };
  }
}
```

### Memcached Commands and Operations

| Command        | Description                            | Example                      |
| -------------- | -------------------------------------- | ---------------------------- |
| `get <key>`    | Retrieve a value associated with a key | `get user:123`               |
| `set <key>`    | Set a value with a specific key        | `set user:123 0 900 "Alice"` |
| `delete <key>` | Delete a value associated with a key   | `delete user:123`            |
| `flush_all`    | Invalidate all cache data              | `flush_all`                  |
| `stats`        | Display server statistics              | `stats`                      |

### Monitoring Memcached

You can use tools like `telnet` or `nc` to connect to Memcached and issue commands:

```bash
telnet localhost 11211
```

To check stats:

```text
stats
```

### Best Practices

1. **Use Consistent Hashing**: When using multiple Memcached servers, consistent hashing ensures data distribution remains balanced even if nodes are added or removed.
2. **Set Expiry Times**: Always set an expiry time for cache entries to prevent stale data.
3. **Cache Invalidation**: Ensure proper cache invalidation to maintain data consistency between the cache and the source.
4. **Monitor Performance**: Use monitoring tools to track cache hit rates, memory usage, and key evictions.

### Conclusion

Memcached is a lightweight and powerful tool for caching in-memory data, especially useful for reducing database loads in high-traffic environments. However, it requires careful handling of key expiration and cache invalidation strategies. With proper integration, it can significantly boost the performance of web applications.
