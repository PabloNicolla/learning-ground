# CIDR Notation

- [CIDR Notation](#cidr-notation)
  - [Introduction](#introduction)
  - [IP Ranges and CIDR Notation](#ip-ranges-and-cidr-notation)
  - [Common CIDR Blocks](#common-cidr-blocks)
  - [Why Different Sizes?](#why-different-sizes)
  - [Usage in VNets](#usage-in-vnets)

## Introduction

In networking, IP ranges and their notation using CIDR (Classless Inter-Domain Routing) blocks like /24 or /16 are crucial for defining network segments, often within Virtual Networks (VNets) in cloud environments like Azure or AWS.

## IP Ranges and CIDR Notation

- CIDR Notation: This is a method for allocating IP addresses and routing IP packets. It consists of an IP address, followed by a slash (/), and then a number indicating the number of bits in the subnet mask.

- IP Address: An IP address (IPv4) is a 32-bit number, typically written in dotted-decimal format, like 192.168.1.0.

- Subnet Mask: This defines which portion of the IP address represents the network and which part represents the host. The number after the slash in CIDR notation (e.g., /24) indicates the number of bits that are set to "1" in the subnet mask.

## Common CIDR Blocks

- /24 Subnet (e.g., 192.168.1.0/24):
  - Subnet Mask: 255.255.255.0
  - Number of Addresses: 256 (2^8, since 32 - 24 = 8 bits are left for host addresses)
  - Usable Addresses: 254 (excluding the network address and broadcast address)
  - Typical Use: A /24 subnet is often used for smaller networks, such as a department or a small office, where up to 254 devices need to be connected.

- /16 Subnet (e.g., 192.168.0.0/16):
  - Subnet Mask: 255.255.0.0
  - Number of Addresses: 65,536 (2^16)
  - Usable Addresses: 65,534
  - Typical Use: A /16 subnet is suitable for larger networks, such as a large office or an organization with multiple departments. It allows for a significant number of devices to be connected.

## Why Different Sizes?

- /24 (Smaller Networks): When you know your network will not exceed 254 devices, /24 is efficient and avoids wasting IP addresses.

- /16 (Larger Networks): When a larger network is required, with possibly thousands of devices, /16 is more appropriate. This can be useful in cloud environments where scalability is a concern, such as allocating a large range of IPs within a VNet to accommodate multiple subnets.

## Usage in VNets

- In Azure or AWS VNets:
  - /24 Subnets are typically used for smaller subnets within a VNet, such as a subnet for a particular application or service.
  - /16 VNets might be allocated to an entire virtual network in a cloud environment, with further subnets defined within it.

These CIDR blocks and subnetting concepts are essential for designing and scaling networks effectively, whether on-premises or in the cloud.
