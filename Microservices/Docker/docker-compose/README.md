# Docker compose

- [Docker compose](#docker-compose)
  - [Create](#create)
  - [Read](#read)
  - [Update](#update)
  - [Delete](#delete)
  - [Debugging and Troubleshooting Docker Compose Commands](#debugging-and-troubleshooting-docker-compose-commands)

## Create

```bash
# Check the Docker Compose version installed on your system.
docker-compose --version

# Create and start containers as defined in the docker-compose.yml file.
docker-compose up
# To run in detached mode
docker-compose up -d

# Build or rebuild services.
docker-compose build

# Build images before starting containers.
docker-compose up --build

# Set the number of containers to run for a service.
docker-compose scale <service_name>=<number>

# Pull the specified images from the registry.
docker-compose pull

# Pull a specific service image from the registry.
docker-compose pull <service_name>

# Run a one-off command on a service.
docker-compose run <service_name> <command>
```

## Read

```bash
# List containers that are part of the Docker Compose application.
docker-compose ps

# View output from containers.
docker-compose logs
# To follow logs in real-time
docker-compose logs -f

# Display the running processes of services.
docker-compose top

# Print the public port for a port binding.
docker-compose port <service_name> <private_port>

# Validate and view the Compose file.
docker-compose config
```

## Update

```bash
# Start existing containers.
docker-compose start

# Restart all the services defined in the docker-compose.yml file.
docker-compose restart

# Execute a command in a running service container.
docker-compose exec <service_name> <command>
# For example, to get a shell inside a web service
docker-compose exec web /bin/bash

# Pause services.
docker-compose pause

# Unpause services.
docker-compose unpause
```

## Delete

```bash
# Stop and remove containers, networks, images, and volumes defined in the docker-compose.yml file.
docker-compose down

# Stop running containers without removing them.
docker-compose stop

# Remove stopped service containers.
docker-compose rm

# Force stop service containers.
docker-compose kill

# Stop and remove containers, networks, images, and volumes.
docker-compose down --volumes
```

## Debugging and Troubleshooting Docker Compose Commands

```bash
# Dump build logs into file
docker-compose build --no-cache > build_output.txt 2>&1

# enter container
docker-compose exec <service> bash

# list network
docker network ls
```
