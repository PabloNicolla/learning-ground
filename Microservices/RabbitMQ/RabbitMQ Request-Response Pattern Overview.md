# RabbitMQ Request-Response Pattern Overview

- [RabbitMQ Request-Response Pattern Overview](#rabbitmq-request-response-pattern-overview)
  - [Introduction](#introduction)
  - [Basic Concept](#basic-concept)
  - [Example Implementation](#example-implementation)
    - [Server Code](#server-code)
    - [Client Code](#client-code)
  - [Key Components](#key-components)

## Introduction

The request-response pattern in RabbitMQ allows clients to send requests and receive responses asynchronously. Here's how it works:

## Basic Concept

1. Client creates a temporary response queue
2. Client sends a request message with `reply_to` property set to response queue
3. Server processes request and sends response to specified queue
4. Client receives response from its temporary queue

## Example Implementation

### Server Code

```python
import pika
import json

def process_request(request):
    # Simulate processing
    return f"Processed: {request}"

def on_request(ch, method, props, body):
    request = json.loads(body)
    response = process_request(request)
    
    ch.basic_publish(
        exchange='',
        routing_key=props.reply_to,
        properties=pika.BasicProperties(
            correlation_id=props.correlation_id
        ),
        body=json.dumps(response)
    )
    ch.basic_ack(delivery_tag=method.delivery_tag)

# Setup connection
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

# Declare request queue
channel.queue_declare(queue='rpc_queue')
channel.basic_qos(prefetch_count=1)
channel.basic_consume(queue='rpc_queue', on_message_callback=on_request)

print("Server waiting for requests...")
channel.start_consuming()
```

### Client Code

```python
import pika
import uuid
import json

class RpcClient:
    def __init__(self):
        self.connection = pika.BlockingConnection(
            pika.ConnectionParameters('localhost')
        )
        self.channel = self.connection.channel()
        
        # Create callback queue
        result = self.channel.queue_declare(queue='', exclusive=True)
        self.callback_queue = result.method.queue
        
        self.channel.basic_consume(
            queue=self.callback_queue,
            on_message_callback=self.on_response,
            auto_ack=True
        )
        
    def on_response(self, ch, method, props, body):
        if self.corr_id == props.correlation_id:
            self.response = json.loads(body)
    
    def call(self, request):
        self.response = None
        self.corr_id = str(uuid.uuid4())
        
        self.channel.basic_publish(
            exchange='',
            routing_key='rpc_queue',
            properties=pika.BasicProperties(
                reply_to=self.callback_queue,
                correlation_id=self.corr_id,
            ),
            body=json.dumps(request)
        )
        
        while self.response is None:
            self.connection.process_data_events()
        return self.response

# Usage
client = RpcClient()
print(client.call("Hello World"))
```

## Key Components

- **Correlation ID**: Unique identifier to match requests with responses
- **Reply-to Queue**: Temporary queue for receiving responses
- **Basic Properties**: Used to pass metadata between client and server
- **QoS Settings**: Controls message distribution among workers
