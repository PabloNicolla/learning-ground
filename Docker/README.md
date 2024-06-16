# Docker

## Create

```bash
# Download a Docker image from a registry (e.g., Docker Hub).
docker pull <image_name>

# Create and start a new container from an image.
docker run -d -p 80:80 <image_name>

# Build an image from a Dockerfile.
docker build -t <image_name>:<optional-flag> .

# Create a new network.
docker network create <network_name>

# Create a new volume.
docker volume create <volume_name>

# Create a new image from a container’s changes.
docker commit <container_id> <new_image_name>
```

## Read

```bash
# Check the Docker version installed on your system.
docker --version

# List all Docker images on your local system.
docker images

# List all running containers.
docker ps

# List all containers (running and stopped).
docker ps -a

# Fetch the logs of a container.
docker logs <container_id>

# List all networks.
docker network ls

# List all volumes.
docker volume ls

# Display detailed information about a container or image.
docker inspect <container_id_or_image_name>

# Display a live stream of container(s) resource usage statistics.
docker stats

# Display the running processes of a container.
docker top <container_id>

# Get real-time events from the Docker server.
docker events

# Inspect changes to files or directories on a container’s filesystem.
docker diff <container_id>

# Show the history of an image.
docker history <image_name>

# Show docker disk usage.
docker system df

# Display system-wide information about Docker, including number of containers, images, storage driver, and more.
docker info
```

## Update

```bash
# Start a stopped container.
docker start <container_id>

# Restart a running container.
docker restart <container_id>

# Run a command in a running container.
docker exec -it <container_id> <command>

# Rename a container.
docker rename <old_container_name> <new_container_name>

# Update configuration of one or more containers.
docker update --cpus 2 <container_id>
```

## Delete

```bash
# Remove one or more Docker images.
docker rmi <image_name>

# Stop a running container.
docker stop <container_id>

# Remove one or more stopped containers.
docker rm <container_id>

# Remove one or more networks.
docker network rm <network_name>

# Remove one or more volumes.
docker volume rm <volume_name>

# Remove all unused containers, networks, images (both dangling and unreferenced), and optionally, volumes.
docker system prune
# With the `-a` flag, it will remove all unused images, not just dangling ones
docker system prune -a
```

## Debugging and Troubleshooting Docker Commands

```bash
# Fetch the logs of a container (with optional flags for more control).
docker logs <container_id>
# To follow logs in real-time
docker logs -f <container_id>
# To limit the number of lines
docker logs --tail 100 <container_id>

# Run a command in a running container (useful for getting a shell inside the container).
docker exec -it <container_id> /bin/bash
# or
docker exec -it <container_id> /bin/sh

# Copy files or directories between a container and the local filesystem.
docker cp <container_id>:<container_path> <host_path>
docker cp <host_path> <container_id>:<container_path>

# Attach local standard input, output, and error streams to a running container.
docker attach <container_id>

# Pause all processes within a container.
docker pause <container_id>

# Unpause all processes within a container.
docker unpause <container_id>
```

## Docker Hub push

Create and push

```bash
# Create an image from a Dockerfile:
docker build -t <your_username>/<image_name>:<tag> .

# Log in to Docker Hub:
docker login

# Push the image to Docker Hub:
docker push <your_username>/<image_name>:<tag>
```

Push an existing image

```bash
# Tag the existing image:
docker tag <image_name> <your_username>/<image_name>:<tag>

# Push the image to Docker Hub:
docker push <your_username>/<image_name>:<tag>
```
