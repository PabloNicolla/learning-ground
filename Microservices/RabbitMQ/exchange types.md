# exchange types

- [exchange types](#exchange-types)
  - [Introduction](#introduction)
  - [Exchange-Exchange Routing](#exchange-exchange-routing)

## Introduction

In RabbitMQ, topics are used to define routing patterns for messages, typically within **Topic Exchanges**. RabbitMQ has different exchange types, each with distinct ways to route messages based on routing keys. The main topic types or routing patterns that you can set in RabbitMQ include:

1. **Direct Exchange**: Routes messages to queues based on an exact match between the message routing key and the queue's binding key. If a message’s routing key is `"info"`, it will only be delivered to queues bound to the exchange with that exact `"info"` binding key.

2. **Fanout Exchange**: Routes messages to all bound queues regardless of the routing key. It broadcasts messages to all queues connected to it, making it ideal for broadcasting events to multiple consumers.

3. **Topic Exchange**: Uses patterns to match routing keys to queues. This allows routing messages to multiple queues based on wildcard rules in the routing key. The routing key can contain:
   - `*` - Matches exactly one word.
   - `#` - Matches zero or more words.
   For example, a routing key of `"log.*.error"` would match `"log.app.error"` but not `"log.app.system.error"`, while `"log.#"` would match any routing keys that start with `"log."`.

4. **Headers Exchange**: Routes messages based on header attributes rather than the routing key. Messages with headers that match the queue’s required headers will be routed to that queue. Headers exchanges support more complex matching but are less commonly used compared to topic exchanges.

Each of these types gives flexibility in how messages are directed to specific queues based on your system’s requirements. The **Topic Exchange** is the most common when you want to define complex routing patterns using topics.

> [!NOTE]
> Read more about [Topic Exchange](<Comprehensive Guide to RabbitMQ Topic Exchanges.md>)

## Exchange-Exchange Routing

One exchange can send messages to another exchange.
