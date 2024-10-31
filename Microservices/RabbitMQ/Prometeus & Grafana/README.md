# RabbitMQ Monitoring Setup Guide with Prometheus and Grafana

- [RabbitMQ Monitoring Setup Guide with Prometheus and Grafana](#rabbitmq-monitoring-setup-guide-with-prometheus-and-grafana)
  - [Introduction](#introduction)
  - [Prerequisites](#prerequisites)
  - [Project Setup](#project-setup)
  - [Configuration Files](#configuration-files)
    - [1. RabbitMQ Plugins Configuration](#1-rabbitmq-plugins-configuration)
    - [2. Prometheus Configuration](#2-prometheus-configuration)
    - [3. Docker Compose Configuration](#3-docker-compose-configuration)
  - [Deployment Steps](#deployment-steps)
  - [Access Points \& Credentials](#access-points--credentials)
    - [RabbitMQ Management UI](#rabbitmq-management-ui)
    - [Prometheus UI](#prometheus-ui)
    - [Grafana](#grafana)
  - [Grafana Setup](#grafana-setup)
  - [Maintenance Commands](#maintenance-commands)
  - [Port Reference](#port-reference)
  - [Troubleshooting](#troubleshooting)

## Introduction

This guide walks through setting up RabbitMQ monitoring using Prometheus and Grafana on Windows 11 with Docker Desktop.

## Prerequisites

- Windows 11
- Docker Desktop installed and running
- Basic familiarity with command line operations

## Project Setup

1. Create the project directory structure:

```bash
mkdir rabbitmq-monitoring
cd rabbitmq-monitoring
mkdir prometheus_config
mkdir rabbitmq_config
```

## Configuration Files

### 1. RabbitMQ Plugins Configuration

Create `rabbitmq_config/enabled_plugins` with the following content:

```text
[rabbitmq_management,rabbitmq_prometheus].
```

### 2. Prometheus Configuration

Create `prometheus_config/prometheus.yml` with the following content:

```yaml
global:
  scrape_interval: 15s
  evaluation_interval: 15s

scrape_configs:
  - job_name: "rabbitmq"
    static_configs:
      - targets: ["rabbitmq:15692"]
```

### 3. Docker Compose Configuration

Create `docker-compose.yml` in the root directory:

```yaml
version: "3.8"
services:
  rabbitmq:
    image: rabbitmq:3-management
    container_name: rabbitmq
    ports:
      - "5672:5672"   # AMQP protocol port
      - "15672:15672" # Management UI port
    environment:
      - RABBITMQ_DEFAULT_USER=guest
      - RABBITMQ_DEFAULT_PASS=guest
    volumes:
      - rabbitmq_data:/var/lib/rabbitmq
      - ./rabbitmq_config/enabled_plugins:/etc/rabbitmq/enabled_plugins
    healthcheck:
      test: ["CMD", "rabbitmq-diagnostics", "check_port_connectivity"]
      interval: 30s
      timeout: 30s
      retries: 3

  prometheus:
    image: prom/prometheus:latest
    container_name: prometheus
    ports:
      - "9090:9090"
    volumes:
      - ./prometheus_config/prometheus.yml:/etc/prometheus/prometheus.yml
      - prometheus_data:/prometheus
    command:
      - '--config.file=/etc/prometheus/prometheus.yml'
      - '--storage.tsdb.path=/prometheus'
      - '--web.console.libraries=/etc/prometheus/console_libraries'
      - '--web.console.templates=/etc/prometheus/consoles'
    depends_on:
      - rabbitmq

  grafana:
    image: grafana/grafana:latest
    container_name: grafana
    ports:
      - "3000:3000"
    environment:
      - GF_SECURITY_ADMIN_USER=admin
      - GF_SECURITY_ADMIN_PASSWORD=admin
    volumes:
      - grafana_data:/var/lib/grafana
    depends_on:
      - prometheus

volumes:
  rabbitmq_data:
  prometheus_data:
  grafana_data:
```

## Deployment Steps

1. Start the stack:

```bash
docker-compose up -d
```

2. Verify all containers are running:

```bash
docker-compose ps
```

## Access Points & Credentials

### RabbitMQ Management UI

- URL: `http://localhost:15672`
- Username: guest
- Password: guest

### Prometheus UI

- URL: `http://localhost:9090`

### Grafana

- URL: `http://localhost:3000`
- Username: admin
- Password: admin

## Grafana Setup

1. Log into Grafana at `http://localhost:3000`

2. Configure Prometheus Data Source:
   - Navigate to Configuration > Data Sources
   - Click "Add data source"
   - Select "Prometheus"
   - Set URL to "`http://prometheus:9090`"
   - Click "Save & Test"

3. Import RabbitMQ Dashboard:
   - Click the "+" symbol in the left sidebar
   - Select "Import"
   - Enter dashboard ID: 10991
   - Select your Prometheus data source in the dropdown
   - Click "Import"

## Maintenance Commands

Stop the stack:

```bash
docker-compose down
```

Stop and remove all data:

```bash
docker-compose down -v
```

View logs:

```bash
docker-compose logs -f
```

## Port Reference

- 5672: RabbitMQ AMQP
- 15672: RabbitMQ Management UI
- 15692: RabbitMQ Prometheus metrics
- 9090: Prometheus UI
- 3000: Grafana UI

## Troubleshooting

If services don't start properly:

1. Check Docker Desktop is running
2. Ensure no other services are using the required ports
3. View logs with `docker-compose logs -f`
4. Restart the stack with:

```bash
docker-compose down
docker-compose up -d
```
