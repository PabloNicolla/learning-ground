# Essential RabbitMQ Plugins Guide

- [Essential RabbitMQ Plugins Guide](#essential-rabbitmq-plugins-guide)
  - [1. RabbitMQ Management Plugin](#1-rabbitmq-management-plugin)
    - [Summary](#summary)
    - [Activation](#activation)
    - [Usage](#usage)
  - [2. Shovel Plugin](#2-shovel-plugin)
    - [Summary](#summary-1)
    - [Activation](#activation-1)
    - [Usage](#usage-1)
  - [3. Federation Plugin](#3-federation-plugin)
    - [Summary](#summary-2)
    - [Activation](#activation-2)
    - [Usage](#usage-2)
  - [4. Delayed Message Exchange](#4-delayed-message-exchange)
    - [Summary](#summary-3)
    - [Activation](#activation-3)
    - [Usage](#usage-3)
  - [5. MQTT Plugin](#5-mqtt-plugin)
    - [Summary](#summary-4)
    - [Activation](#activation-4)
    - [Usage](#usage-4)
  - [6. STOMP Plugin](#6-stomp-plugin)
    - [Summary](#summary-5)
    - [Activation](#activation-5)
    - [Usage](#usage-5)
  - [Best Practices for Plugin Management](#best-practices-for-plugin-management)
  - [Troubleshooting Common Plugin Issues](#troubleshooting-common-plugin-issues)

## 1. RabbitMQ Management Plugin

### Summary

- Provides a web-based UI for managing and monitoring RabbitMQ
- Includes HTTP API for monitoring and management
- Essential for development and production environments

### Activation

```yaml
# In docker-compose.yml
services:
  rabbitmq:
    image: rabbitmq:3-management  # Use management image
    environment:
      - RABBITMQ_PLUGINS=rabbitmq_management
```

Or manually inside container:

```bash
rabbitmq-plugins enable rabbitmq_management
```

### Usage

- Access UI: `http://localhost:15672` (default)
- Default credentials: guest/guest
- Features:
  - Queue/Exchange management
  - User management
  - Performance monitoring
  - Real-time statistics
  - Publish/receive test messages

## 2. Shovel Plugin

### Summary

- Moves messages from one broker to another
- Useful for connecting brokers across networks/data centers
- Supports queue-to-queue, queue-to-exchange transfers

### Activation

```yaml
services:
  rabbitmq:
    environment:
      - RABBITMQ_ENABLED_PLUGINS=rabbitmq_shovel,rabbitmq_shovel_management
```

### Usage

- Configure through management UI or config file
- Supports dynamic or static configurations
- Example configuration:

```erlang
{
    "src-uri": "amqp://source-broker",
    "src-queue": "source_queue",
    "dest-uri": "amqp://dest-broker",
    "dest-queue": "dest_queue"
}
```

## 3. Federation Plugin

### Summary

- Links brokers across WANs
- Provides scalable message routing across sites
- More lightweight than clustering for distributed setups

### Activation

```yaml
services:
  rabbitmq:
    environment:
      - RABBITMQ_ENABLED_PLUGINS=rabbitmq_federation,rabbitmq_federation_management
```

### Usage

- Configure upstream servers in management UI
- Set policies for federation
- Supports exchange-to-exchange message flow

## 4. Delayed Message Exchange

### Summary

- Allows messages to be delivered after a specified delay
- Useful for scheduling and deferred processing

### Activation

```yaml
services:
  rabbitmq:
    image: rabbitmq:3-management
    environment:
      - RABBITMQ_ENABLED_PLUGINS=rabbitmq_delayed_message_exchange
```

### Usage

- Declare exchange with type 'x-delayed-message'
- Set delay in message headers:

```javascript
channel.publish('exchange_name', 'routing_key', content, {
    headers: {
        'x-delay': 5000  // delay in milliseconds
    }
});
```

## 5. MQTT Plugin

### Summary

- Adds MQTT protocol support to RabbitMQ
- Enables IoT device communication
- Supports MQTT 3.1.1

### Activation

```yaml
services:
  rabbitmq:
    environment:
      - RABBITMQ_ENABLED_PLUGINS=rabbitmq_mqtt
    ports:
      - "1883:1883"  # MQTT port
```

### Usage

- Connect MQTT clients to port 1883
- Supports QoS levels 0,1
- Integrates with existing AMQP infrastructure

## 6. STOMP Plugin

### Summary

- Adds STOMP protocol support
- Useful for web applications
- Enables WebSocket connections

### Activation

```yaml
services:
  rabbitmq:
    environment:
      - RABBITMQ_ENABLED_PLUGINS=rabbitmq_stomp,rabbitmq_web_stomp
    ports:
      - "61613:61613"  # STOMP port
      - "15674:15674"  # WebSTOMP port
```

### Usage

- Connect STOMP clients to port 61613
- WebSocket connections on port 15674
- Ideal for web-based messaging

## Best Practices for Plugin Management

1. **Multiple Plugin Activation**

```yaml
services:
  rabbitmq:
    environment:
      - RABBITMQ_ENABLED_PLUGINS=rabbitmq_management,rabbitmq_shovel,rabbitmq_federation
```

2. **Plugin Dependencies**

- Some plugins require others to function
- Management UI plugins often need base plugin
- Check documentation for dependencies

3. **Resource Considerations**

- Each plugin consumes additional resources
- Monitor memory usage
- Enable only necessary plugins

4. **Security Notes**

- Some plugins open additional ports
- Review default credentials
- Configure firewall rules accordingly

5. **Monitoring**

- Use management UI to verify plugin status
- Check logs for plugin-related issues
- Monitor plugin-specific metrics

## Troubleshooting Common Plugin Issues

1. **Plugin Won't Enable**

- Check plugin compatibility with RabbitMQ version
- Verify plugin installation
- Check error logs: `docker logs rabbitmq`

2. **Performance Issues**

- Review enabled plugins
- Monitor resource usage
- Consider disabling unused plugins

3. **Access Issues**

- Verify port mappings in docker-compose
- Check network connectivity
- Review user permissions
