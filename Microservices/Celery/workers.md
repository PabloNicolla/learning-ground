# Workers

- [Workers](#workers)
  - [Introduction](#introduction)
    - [1. **How Does the Worker Know What Task to Perform?**](#1-how-does-the-worker-know-what-task-to-perform)
    - [2. **How Are the Workers Created and Configured to Look at RabbitMQ?**](#2-how-are-the-workers-created-and-configured-to-look-at-rabbitmq)
      - [**Worker Creation (Server 3)**](#worker-creation-server-3)
      - [**How Do Workers Know to Look at RabbitMQ?**](#how-do-workers-know-to-look-at-rabbitmq)
    - [**Summary**](#summary)

## Introduction

### 1. **How Does the Worker Know What Task to Perform?**

When you define a task in the **producer (Server 1)** like this:

```python
@app.task
def send_email(to_address):
    print(f"Sending email to {to_address}")
```

This task is part of a Celery application instance (`app`). The task definition includes **metadata** such as:

- The task's **name** (default is the function name, `send_email` in this case).
- The **arguments** it expects.
- The **module** or file in which it is defined.

When you start a **Celery worker** on **Server 3**, it will load the **Celery application instance** (the `app` in your code) and **register the tasks** it can handle.

**Example**:

```bash
celery -A producer worker --loglevel=info
```

Here, the `-A producer` tells Celery to look at the `producer.py` file (or module named `producer`) to import the Celery app instance (`app`). This process includes:

1. **Importing Tasks**: The worker loads and imports all the tasks defined in the Celery app, like `send_email`.
2. **Registering Tasks**: It registers these tasks locally, so it knows which tasks it can handle when RabbitMQ assigns one.

**Key Points**:

- Both the **producer** and the **worker** share the same codebase or a compatible codebase where the task is defined.
- When a task is sent from the producer to the broker, it includes metadata like the task name (`send_email`) and its arguments (`to_address`).
- The worker identifies the task using this metadata because it has already registered the task during startup.

**Example of Task Metadata** sent to RabbitMQ:

```json
{
  "id": "some-unique-id",
  "task": "producer.send_email",
  "args": ["example@example.com"],
  "kwargs": {},
  "retries": 0
}
```

The worker looks up the task name (`producer.send_email`), matches it with its registered tasks, and then executes the corresponding function.

### 2. **How Are the Workers Created and Configured to Look at RabbitMQ?**

#### **Worker Creation (Server 3)**

- You typically start a Celery worker process using the command line:

  ```bash
  celery -A producer worker --loglevel=info
  ```

  - `-A producer`: Specifies the **Celery app** (defined in `producer.py`).
  - `worker`: Tells Celery to start a worker process.
  - `--loglevel=info`: Sets the log verbosity.

- This command initializes the worker, loads the Celery app instance, and registers the tasks.

#### **How Do Workers Know to Look at RabbitMQ?**

The connection to RabbitMQ (or any broker) is configured in the **Celery app instance** using a **configuration setting**:

```python
from celery import Celery

# Celery app initialization
app = Celery(
    'producer',
    broker='amqp://user:password@rabbitmq-server:5672//',  # Connection to RabbitMQ
    backend='redis://redis-server:6379/0'  # Optional result backend
)
```

**How This Works**:

1. **Configuration in Code**:
   - The **broker URL** (`amqp://user:password@rabbitmq-server:5672//`) tells Celery to connect to RabbitMQ.
   - This URL is passed to the Celery worker when it initializes, allowing it to establish a connection to RabbitMQ.

2. **Connecting to RabbitMQ**:
   - Upon startup, the worker uses the **broker URL** from the Celery app configuration to connect to RabbitMQ.
   - The worker subscribes to specific task queues (e.g., the default queue if none is specified, or custom queues if defined in the task).

3. **Consuming Tasks**:
   - Once connected, the worker listens for messages (tasks) on the queue. RabbitMQ dispatches tasks to the worker based on availability.
   - The worker pulls the task message, looks up the task by name (e.g., `producer.send_email`), and executes it.

**Example Worker Startup Command with Explicit Queue**:

```bash
celery -A producer worker --loglevel=info -Q email_queue
```

**Specifying a Queue**:

- You can specify which **queues** the worker should listen to using the `-Q` option. This is useful if you want to segregate tasks (e.g., email tasks, data processing tasks).

**Example Task with Specific Queue**:

```python
@app.task(queue='email_queue')
def send_email(to_address):
    print(f"Sending email to {to_address}")
```

### **Summary**

- **Task Discovery**:
  - The **worker** knows what tasks to execute because it loads the Celery app instance at startup, which includes all defined tasks.
- **Connection to RabbitMQ**:
  - The **connection details** to RabbitMQ are specified in the Celery app configuration (`broker='amqp://...'`).
  - The worker reads this configuration and connects to the specified RabbitMQ server to listen for tasks.
- **Execution**:
  - When a task is added to RabbitMQ by the producer, it includes the task's name and arguments.
  - The worker matches the task's name with its registered tasks and executes the corresponding function.

This architecture allows Celery workers to be easily scaled out across multiple servers, as they only need the Celery app instance with the task definitions and the RabbitMQ connection details to function properly.
