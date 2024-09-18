# Private vs. Public IPs

## Detailed Overview

In networking, IP addresses serve as unique identifiers for devices connected to a network. There are two main types of IP addresses: Private IP addresses and Public IP addresses. Here’s a breakdown of the key differences between them:

## Private IP Addresses

- Definition: These are IP addresses used within a private network. Devices that use private IPs can communicate with other devices on the same network but not directly with the internet.

- IP Ranges (as defined by the Internet Assigned Numbers Authority, IANA):
  - Class A: 10.0.0.0 - 10.255.255.255
  - Class B: 172.16.0.0 - 172.31.255.255
  - Class C: 192.168.0.0 - 192.168.255.255

- Example: Your home router likely assigns devices on your local network IPs like 192.168.1.10.

- Use Cases:
  - Home and Corporate Networks: Routers assign private IPs to devices like computers, printers, phones, etc.
  - Network Isolation: Private IPs keep devices within the same network isolated from the internet.
  - NAT (Network Address Translation): Allows devices with private IPs to connect to the internet through a single public IP.

- Characteristics:
  - Cannot be routed on the internet: These IPs are only valid within private networks and are not visible or accessible directly from the internet.
  - Reused Across Different Networks: Private IPs can be the same on different private networks (e.g., multiple home networks can have a device with 192.168.1.10).
  - Security: Since they aren't accessible from outside the local network, private IPs inherently add a layer of security.

## Public IP Addresses

- Definition: Public IPs are globally unique IP addresses used to identify devices on the internet. Every internet-connected device must have a public IP (directly or through a shared public IP via NAT).

- IP Ranges: All IPs not reserved for private use fall under public IPs (except special-use IPs like multicast, experimental ranges, etc.).

- Use Cases:
  - Internet-Facing Servers: Websites, mail servers, and other services accessible on the internet use public IPs.
  - Routers with NAT: Your home router is assigned a public IP by your ISP, allowing devices in your home network to connect to the internet.

- Characteristics:
  - Globally Unique: Each public IP address is unique across the entire internet.
  - Internet-Routable: Public IP addresses are routable on the internet, meaning they can be accessed from any location globally.
  - Scarcity: IPv4 addresses are becoming scarce, leading to the deployment of IPv6 (which offers a much larger address space).

## Comparison Table

| Feature            | Private IP Addresses                           | Public IP Addresses                      |
| ------------------ | ---------------------------------------------- | ---------------------------------------- |
| Visibility         | Only within private networks                   | Visible and accessible on the internet   |
| IP Ranges          | 10.x.x.x, 172.16.x.x – 172.31.x.x, 192.168.x.x | Any IP not in private or reserved ranges |
| Global Uniqueness  | Can be reused across different networks        | Must be globally unique                  |
| Security           | More secure (not directly accessible)          | Less secure (can be attacked)            |
| Internet Access    | No direct access (uses NAT for internet)       | Direct internet access                   |
| Use Case           | Local communication within a network           | Global communication on the internet     |
| Address Exhaustion | Not an issue (can be reused)                   | Limited pool in IPv4 (solved by IPv6)    |

## How They Work Together

- NAT (Network Address Translation) is used to allow devices with private IPs to connect to the internet via a router that has a public IP.
- Example: In a home network, your router has a public IP assigned by your ISP. The devices connected to your router use private IP addresses. When a device sends traffic to the internet, the router translates the private IP into the public IP, and when data is returned, it translates the public IP back to the private IP.

## IP Addressing and NAT in Practice

- Home Networks: Most home networks operate with private IP addresses (like 192.168.1.x). The router uses NAT to enable these devices to share a single public IP when accessing the internet.
- Cloud Environments: In cloud services like AWS, instances might have both public and private IPs. The private IP is for internal communication between instances, and the public IP is for internet communication.

## Example

When your PC with the private IP 10.1.1.1 sends a request to the server with public IP 3.3.3.3, the router with public IP 2.2.2.2 performs Network Address Translation (NAT). Here’s what happens in detail:

### Request from your PC (10.1.1.1) to the Router (2.2.2.2)

- Your PC sends a packet to the server 3.3.3.3. The packet has:
  - Source IP: 10.1.1.1 (your PC’s private IP)
  - Destination IP: 3.3.3.3 (the server’s public IP)

### NAT Process in the Router

- When the packet reaches your router, NAT kicks in. The router replaces your PC's private IP (10.1.1.1) with the router’s public IP (2.2.2.2) before sending the packet to the server.
  - The new packet will now have:
    - Source IP: 2.2.2.2 (the router's public IP)
    - Destination IP: 3.3.3.3 (the server's public IP)

- However, the router does keep a reference of your PC’s private IP (10.1.1.1) and the port used for this connection. This reference is stored in a NAT table. The router creates an entry in this table that maps:
  - Source Private IP and Port: 10.1.1.1:portA
  - Translated Public IP and Port: 2.2.2.2:portB

- This allows the router to remember which device on the internal network initiated the request.

### The Server Response (3.3.3.3) to the Router (2.2.2.2)

- The server 3.3.3.3 receives the packet with the source IP as 2.2.2.2 (your router’s public IP) and sends the response back to that IP (because that’s the source IP it saw).
  - The response packet will have:
    - Source IP: 3.3.3.3
    - Destination IP: 2.2.2.2

### NAT Translation Back at the Router

- When the router receives the response from 3.3.3.3, it checks its NAT table to find the original private IP (10.1.1.1) and port for this connection.
- The router translates the destination IP from 2.2.2.2 back to 10.1.1.1 and forwards the response to your PC.

### Key Point

- The private IP (10.1.1.1) is not included in the request that is sent to the server. The server only sees the public IP of the router (2.2.2.2).
- The router keeps a NAT table that tracks the mapping between the internal private IP (10.1.1.1) and the external public IP (2.2.2.2) so that it knows where to send the server’s response.

## Closing

This distinction is fundamental in networking, ensuring efficient use of IP address space and maintaining security within private networks while still enabling devices to communicate over the internet.
