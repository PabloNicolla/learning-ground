# Route Table

- [Route Table](#route-table)
  - [Introduction](#introduction)
  - [What is a Route Table?](#what-is-a-route-table)
  - [Key Components of a Route Table](#key-components-of-a-route-table)
  - [Default Route Table](#default-route-table)
  - [Custom Route Tables](#custom-route-tables)
  - [Associating Route Tables with Subnets](#associating-route-tables-with-subnets)
  - [Example Scenario](#example-scenario)
  - [Summary](#summary)
  - [Useful links](#useful-links)

## Introduction

In a Virtual Private Cloud (VPC), route tables play a crucial role in determining how network traffic is directed within the VPC and between the VPC and external networks. Let’s break down what route tables are, how they function, and their significance within a VPC.

## What is a Route Table?

A route table in a VPC is a set of rules, known as routes, that dictate how data packets should be routed across different networks. Each subnet in a VPC is associated with a route table that controls the routing of traffic within the VPC and beyond.

## Key Components of a Route Table

- Destination: The destination CIDR block for the traffic, which can be an IP range or a specific IP address. This defines where the traffic is intended to go.

- Target: The next hop for the traffic that matches the destination. This could be:
  - Local: For traffic within the VPC (i.e., communication between subnets).
  - Internet Gateway (IGW): For traffic destined for the internet.
  - NAT Gateway: For instances in private subnets to access the internet.
  - VPC Peering Connection: For communication between VPCs.
  - Virtual Private Gateway: For traffic destined for an on-premises network through a VPN.
  - Network Interface: For directing traffic to a specific instance within the VPC.
  - Instance ID: Directs traffic to a particular instance, often used in custom routing setups.

- Propagated Routes: These are routes that are automatically added to the route table by a Virtual Private Gateway, typically when a VPN connection is established.

## Default Route Table

- Local Route: Every VPC automatically has a route table known as the Main Route Table. It includes a default "local" route, which allows communication within the VPC (i.e., between subnets).

## Custom Route Tables

- You can create custom route tables in a VPC to tailor routing for specific subnets. For example, a subnet that needs to access the internet might have a route table with a route to the Internet Gateway (IGW).

## Associating Route Tables with Subnets

- Each subnet in a VPC must be associated with a route table. By default, subnets are associated with the Main Route Table, but you can associate them with a custom route table if you need specific routing rules.

## Example Scenario

Let’s say you have a VPC with two subnets:

- Public Subnet (10.0.1.0/24): This subnet is associated with a route table that has:
  - Destination: 0.0.0.0/0 (This represents all IP addresses)
  - Target: Internet Gateway (IGW)

- Private Subnet (10.0.2.0/24): This subnet is associated with a different route table that has:
  - Destination: 0.0.0.0/0
  - Target: NAT Gateway (for internet-bound traffic from the private subnet)

In this scenario, instances in the public subnet can directly access the internet because their traffic is routed through the IGW. However, instances in the private subnet can access the internet only through the NAT Gateway, ensuring they don’t have direct exposure to the internet.
Use Cases

- Internet Access: By configuring a route to an Internet Gateway in the route table, instances can access the internet.
- VPN Connections: Routes to a Virtual Private Gateway allow instances to communicate with an on-premises network.
- VPC Peering: Routes to a VPC Peering Connection enable communication between two VPCs.
- Custom Routing: You can implement specific routing rules for traffic to pass through firewalls, proxies, or other network devices.

## Summary

Route tables in a VPC are essential for controlling how traffic flows within the VPC and to external networks. They ensure that network traffic is directed according to the desired paths, enabling secure and efficient communication within the cloud environment.

## Useful links

[Routing Table Video](https://www.youtube.com/watch?v=pbqc6IlFuVc)
