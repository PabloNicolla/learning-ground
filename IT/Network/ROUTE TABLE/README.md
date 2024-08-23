# Route Table

- [Route Table](#route-table)
  - [Introduction](#introduction)
  - [What is a Route Table?](#what-is-a-route-table)
  - [Key Components of a Route Table](#key-components-of-a-route-table)
  - [Default Route Table](#default-route-table)
  - [Custom Route Tables](#custom-route-tables)
  - [Associating Route Tables with Subnets](#associating-route-tables-with-subnets)
  - [Example Scenario](#example-scenario)
  - [Why the Term "Destination" is Used](#why-the-term-destination-is-used)
  - [How It Works in Practice](#how-it-works-in-practice)
  - [Best Match Logic](#best-match-logic)
  - [Why 0.0.0.0/0 Works as a Default Route](#why-00000-works-as-a-default-route)
  - [Is 1.1.1.1/0 the same as 0.0.0.0/0?](#is-11110-the-same-as-00000)
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

## Why the Term "Destination" is Used

- Network Perspective: A route table operates from the perspective of routing traffic towards a destination. The key function of a route table is to decide where to send packets that are leaving a subnet or instance, based on their intended destination IP address.

- Routing Logic: When a packet is ready to leave an instance or subnet, the route table looks at the packet's destination IP address. It then matches this IP address to one of the destinations listed in the route table and forwards the packet to the corresponding target.

## How It Works in Practice

Imagine you're sending a letter:

- Destination (in route table): The address on the letter where it should be delivered.
- Target (in route table): The mail carrier or route that will deliver the letter to the destination.

So, if your instance sends a packet destined for 8.8.8.8, the route table will look for a matching destination (like 0.0.0.0/0 for all external IP addresses) and forward the packet to the appropriate target, such as an Internet Gateway, to reach its final destination.

## Best Match Logic

- Destination IP: 10.10.4.1
- Routes:
  - 10.10.4.0/24
  - 10.10.0.0/16
  - 0.0.0.0/0

In this case:

- 10.10.4.0/24 is the most specific match for 10.10.4.1, because it covers only the range 10.10.4.0 to 10.10.4.255. The subnet mask /24 indicates that the first 24 bits of the IP address must match, making it more specific than /16 or /0.

- 10.10.0.0/16 would cover a broader range (10.10.0.0 to 10.10.255.255), but it is less specific than the /24 route.

- 0.0.0.0/0 is the least specific and is known as the default route, which matches any IP address, but it’s only used when no more specific route is found.

## Why 0.0.0.0/0 Works as a Default Route

- 0.0.0.0/0: This route effectively says "match all addresses" because the /0 subnet mask means no bits need to match specifically.

- Default Route Behavior: The key reason 0.0.0.0/0 works as the default route is because of the /0 mask, not because of the 0.0.0.0 IP address itself. The /0 means that it applies to every possible IP address, making it the catch-all or fallback route when no more specific route is found.

## Is 1.1.1.1/0 the same as 0.0.0.0/0?

Yes, in theory, 1.1.1.1/0 is the same as 0.0.0.0/0 in terms of routing behavior.

- Why? The /0 subnet mask indicates that no bits of the IP address need to match any specific pattern. Essentially, it covers all possible IP addresses (0.0.0.0 to 255.255.255.255).
- 1.1.1.1/0: The /0 mask means "match everything," so the actual IP address before the /0 (whether it's 1.1.1.1, 0.0.0.0, or any other IP) doesn't matter; the route applies to all IPs.

In practice, though, 0.0.0.0/0 is the standard way to define a default route, and it's universally understood and used to represent "anywhere" or "any IP address."

## Summary

Route tables in a VPC are essential for controlling how traffic flows within the VPC and to external networks. They ensure that network traffic is directed according to the desired paths, enabling secure and efficient communication within the cloud environment.

## Useful links

[Routing Table Video](https://www.youtube.com/watch?v=pbqc6IlFuVc)
