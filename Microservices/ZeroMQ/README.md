# ZeroMQ

- [ZeroMQ](#zeromq)
  - [Introduction](#introduction)
    - [**In-Depth Overview of ZeroMQ**](#in-depth-overview-of-zeromq)
      - [**1. Introduction to ZeroMQ**](#1-introduction-to-zeromq)
      - [**2. Core Features of ZeroMQ**](#2-core-features-of-zeromq)
      - [**3. Key Messaging Patterns in ZeroMQ**](#3-key-messaging-patterns-in-zeromq)
    - [**4. Setting Up ZeroMQ with TypeScript**](#4-setting-up-zeromq-with-typescript)
      - [**Basic TypeScript Boilerplate**](#basic-typescript-boilerplate)
    - [**5. Request-Reply (REQ/REP)**](#5-request-reply-reqrep)
      - [**REQ (Client) Example**](#req-client-example)
      - [**REP (Server) Example**](#rep-server-example)
      - [**Output**](#output)
    - [**6. Publish-Subscribe (PUB/SUB)**](#6-publish-subscribe-pubsub)
      - [**Publisher Example**](#publisher-example)
      - [**Subscriber Example**](#subscriber-example)
      - [**Output**](#output-1)
    - [**7. Push-Pull (PUSH/PULL)**](#7-push-pull-pushpull)
      - [**PUSH (Producer) Example**](#push-producer-example)
      - [**PULL (Worker) Example**](#pull-worker-example)
      - [**Output**](#output-2)
    - [**8. Advanced Patterns: ROUTER-DEALER**](#8-advanced-patterns-router-dealer)
      - [**Router Example**](#router-example)
      - [**Dealer Example**](#dealer-example)
    - [**9. ZeroMQ Pros and Cons**](#9-zeromq-pros-and-cons)
      - [**Pros:**](#pros)
      - [**Cons:**](#cons)
    - [**10. Use Cases**](#10-use-cases)
    - [**11. Conclusion**](#11-conclusion)

## Introduction

### **In-Depth Overview of ZeroMQ**

#### **1. Introduction to ZeroMQ**

ZeroMQ (0MQ) is a high-performance asynchronous messaging library aimed at scalable and concurrent applications. It provides a message queue but operates as a socket library, enabling communication between multiple systems through various patterns like PUB/SUB, REQ/REP, PUSH/PULL, etc. ZeroMQ is designed to be lightweight and fast, offering a variety of communication protocols:

- **In-Process (`ipc://`)**
- **Inter-Thread (`inproc://`)**
- **TCP (`tcp://`)**
- **Multicast (`pgm://`, `epgm://`)**

#### **2. Core Features of ZeroMQ**

- **Non-blocking I/O:** ZeroMQ provides non-blocking sockets, enabling efficient and scalable applications.
- **Multiple messaging patterns:** Supports several messaging patterns like PUB/SUB, REQ/REP, PUSH/PULL, etc.
- **Transport agnostic:** Works over different transports such as TCP, IPC, or multicast.
- **High performance:** It can handle millions of messages per second with minimal latency.

#### **3. Key Messaging Patterns in ZeroMQ**

1. **Request-Reply (REQ/REP)**
2. **Publish-Subscribe (PUB/SUB)**
3. **Push-Pull (PUSH/PULL)**
4. **Router-Dealer (ROUTER/DEALER)**
5. **Pair (PAIR/PAIR)**

Let's explore these patterns in-depth with examples using TypeScript.

### **4. Setting Up ZeroMQ with TypeScript**

To use ZeroMQ with TypeScript, you need to install `zeromq` library:

```bash
npm install zeromq
```

You can also add TypeScript definitions:

```bash
npm install @types/zeromq --save-dev
```

#### **Basic TypeScript Boilerplate**

```typescript
import * as zmq from "zeromq";

async function main() {
  // Your ZeroMQ code will go here
}

main();
```

### **5. Request-Reply (REQ/REP)**

**REQ/REP** is the simplest pattern where the client sends a request, and the server sends a reply. This pattern is synchronous and waits for the request to complete before sending the next one.

#### **REQ (Client) Example**

```typescript
import * as zmq from "zeromq";

async function reqClient() {
  const sock = new zmq.Request();

  sock.connect("tcp://localhost:5555");
  console.log("Client connected to port 5555");

  for (let i = 0; i < 3; i++) {
    console.log(`Sending request ${i}`);
    await sock.send(`Hello ${i}`);
    const [reply] = await sock.receive();
    console.log(`Received reply ${i}: ${reply.toString()}`);
  }
}

reqClient();
```

#### **REP (Server) Example**

```typescript
import * as zmq from "zeromq";

async function repServer() {
  const sock = new zmq.Reply();

  sock.bind("tcp://*:5555");
  console.log("Server bound to port 5555");

  for await (const [msg] of sock) {
    console.log("Received:", msg.toString());
    await sock.send(`World ${msg.toString().split(' ')[1]}`);
  }
}

repServer();
```

#### **Output**

```text
Client connected to port 5555
Sending request 0
Received reply 0: World 0
...
```

### **6. Publish-Subscribe (PUB/SUB)**

**PUB/SUB** pattern is used for broadcasting messages to multiple subscribers. Publishers send messages without knowing who will receive them, while subscribers can filter messages based on topics.

#### **Publisher Example**

```typescript
import * as zmq from "zeromq";

async function publisher() {
  const sock = new zmq.Publisher();
  await sock.bind("tcp://*:5556");
  console.log("Publisher bound to port 5556");

  while (true) {
    console.log("Sending update");
    await sock.send(["topic1", "Hello subscribers!"]);
    await new Promise((resolve) => setTimeout(resolve, 1000));
  }
}

publisher();
```

#### **Subscriber Example**

```typescript
import * as zmq from "zeromq";

async function subscriber() {
  const sock = new zmq.Subscriber();
  sock.connect("tcp://localhost:5556");
  sock.subscribe("topic1");
  console.log("Subscriber connected and subscribed to topic1");

  for await (const [topic, msg] of sock) {
    console.log(`Received message on ${topic.toString()}: ${msg.toString()}`);
  }
}

subscriber();
```

#### **Output**

```text
Subscriber connected and subscribed to topic1
Received message on topic1: Hello subscribers!
...
```

### **7. Push-Pull (PUSH/PULL)**

**PUSH/PULL** is an asynchronous pattern for task distribution. It allows a producer to distribute tasks to multiple workers.

#### **PUSH (Producer) Example**

```typescript
import * as zmq from "zeromq";

async function producer() {
  const sock = new zmq.Push();
  await sock.bind("tcp://*:5557");
  console.log("Producer bound to port 5557");

  for (let i = 0; i < 10; i++) {
    console.log(`Sending task ${i}`);
    await sock.send(`Task ${i}`);
    await new Promise((resolve) => setTimeout(resolve, 500));
  }
}

producer();
```

#### **PULL (Worker) Example**

```typescript
import * as zmq from "zeromq";

async function worker() {
  const sock = new zmq.Pull();
  sock.connect("tcp://localhost:5557");
  console.log("Worker connected to port 5557");

  for await (const [msg] of sock) {
    console.log(`Received: ${msg.toString()}`);
  }
}

worker();
```

#### **Output**

```text
Worker connected to port 5557
Received: Task 0
Received: Task 1
...
```

### **8. Advanced Patterns: ROUTER-DEALER**

**ROUTER-DEALER** pattern is used for building complex architectures where a router sends messages to multiple dealers.

#### **Router Example**

```typescript
import * as zmq from "zeromq";

async function router() {
  const sock = new zmq.Router();
  await sock.bind("tcp://*:5558");
  console.log("Router bound to port 5558");

  for await (const [identity, msg] of sock) {
    console.log(`Received from ${identity.toString()}: ${msg.toString()}`);
    await sock.send([identity, "Message acknowledged"]);
  }
}

router();
```

#### **Dealer Example**

```typescript
import * as zmq from "zeromq";

async function dealer() {
  const sock = new zmq.Dealer();
  sock.connect("tcp://localhost:5558");
  sock.send("Hello from dealer");
  console.log("Message sent by dealer");

  const [reply] = await sock.receive();
  console.log("Received reply:", reply.toString());
}

dealer();
```

### **9. ZeroMQ Pros and Cons**

#### **Pros:**

- **Low latency and high throughput:** Optimized for performance.
- **Flexibility:** Multiple messaging patterns for various use cases.
- **Transport agnostic:** Supports multiple transport protocols.
- **Scalability:** Handles many connections concurrently.

#### **Cons:**

- **No built-in persistence:** If a consumer is offline, messages may be lost.
- **Manual connection management:** Requires explicit setup and teardown.
- **Complexity:** More complex than traditional message brokers for certain use cases.

### **10. Use Cases**

- **Distributed microservices:** Efficient inter-process communication (IPC).
- **Load balancing:** Task distribution across multiple workers.
- **Real-time data streaming:** Broadcasting data with PUB/SUB.

### **11. Conclusion**

ZeroMQ is a powerful library for building distributed systems, offering flexibility with various messaging patterns. It fits scenarios where low-latency, high-throughput communication is critical. However, it requires careful management of connections and message flows, making it suitable for developers familiar with network programming concepts.
