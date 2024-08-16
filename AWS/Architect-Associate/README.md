# Architect Associate

## AWS INFRASTRUCTURE INTRO

### REGIONS

A geographical area that contains multiple, isolated locations known as Availability Zones.

### AZ

- A physically separate location within a Region.
- Independent power, cooling, and networking to provide high availability and fault tolerance.
- Connected through low-latency, high-bandwidth networks.

## IAM

### Users & Groups

Group can only have users
Users can belong to multiple groups
User can inherit policies from multiple groups

### Policies

RECOMMENDED: **Least Privilege Principle**

- A policy is a JSON document that defines permissions.
- It specifies what actions are allowed or denied on which resources.
- Policies can be attached to IAM users, groups, or roles to grant them permissions.
- There are two main types of policies: managed policies and inline policies

#### Managed Policy

- Managed policies are standalone policies that can be attached to multiple users, groups, or roles.
- There are two types of managed policies:
  - AWS Managed Policies: Created and managed by AWS. They are designed to provide permissions for common use cases.
  - Customer Managed Policies: Created and managed by the user. They offer more flexibility and customization.

#### Inline Policy

- Inline policies are embedded directly into a specific user, group, or role.
- They maintain a strict one-to-one relationship with the identity they are attached to.
- When the identity is deleted, the inline policy is also deleted.
- Inline policies are useful when you want to ensure that the permissions are not inadvertently assigned to the wrong identity.

#### Permissions

- Permissions are the actual actions that are allowed or denied by a policy.
- They define what operations can be performed on specific AWS resources.
- Permissions are specified within the policy document using actions, resources, and conditions.

#### IAM policies Structure

Consists of:

- Version: policy language version, always include "2012-10-17"
- Id: an identifier for the policy **(optional)**
- Statement: one or more individual statements **(required)**

Statements consists of:

- Sid: an identifier for the statement **(optional)**
- Effect: whether the statement allows or denies access (Allow, Deny)
- Principal: account/user/role to which this policy applied to
- Action: list of actions this policy allows or denies
- Resource: list of resources to which the actions applied to
- Condition: conditions for when this policy is in effect **(optional)**

![Policy Example](image.png)

### AWS ACCESS

AWS Management Console: protected by password + MFA
AWS Command Line Interface: protected by access keys
AWS Software Developer Kit - for code: protected by access keys

Access keys are generated on the AWS Console

```text
Access Key ID     === username
Secret Access Key === password
```

#### AWS SDK

Embedded within your application, supports:

- SDKs (JavaScript, Python, PHP, .NET, Ruby, Java, Go, Node.js, C++)
- Mobile SDKs (Android, iOS, ... )
- IoT Device SDKs (Embedded C, Arduino, )

#### AWS CloudShell

"Safer" way to use AWS CLI

### ROLES for services

Just like a user but intended for AWS services.

Some AWS service will need to perform actions on your behalf.
To do so, we will assign permissions to AWS services with IAM Roles.

### IAM Security Tools

#### IAM Credentials Report (account-level)

a report that lists all your account's users and the status of their various
credentials

#### IAM Access Advisor (user-level)

access advisor shows the service permissions granted to a user and when those
services were last accessed.

### IAM Guidelines & Best Practices

- Avoid using Root
- one user = one physical user
- ...

## EC2 Fundamentals

Elastic Compute Cloud (EC2)

Renting virtual machines (EC2)
Storing data on virtual drives (EBS)
Distributing load across machines (ELB)
Scaling the services using an auto-scaling group (ASG)

### EC2 sizing & configuration options

- Operating System (OS): Linux, Windows or Mac OS
- How much compute power & cores (CPU)
- How much random-access memory (RAM)
- How much storage space:
  - Network-attached (EBS & EFS)
  - hardware (EC2 Instance Store)
- Network card: speed of the card, Public IP address
- Firewall rules: security group
- Bootstrap script (configure at first launch): EC2 User Data

- **Bootstrap script** *runs once as root during initial instance boot*
- **EBS** *Elastic Block Store*
- **EFS** *Elastic File System*

### EC2 Types

Naming Convention

(INSTANCE CLASS)(GENERATION).(INSTANCE SIZE)

- General Purpose (t, m): Balanced compute, memory, and networking for diverse workloads
  - (t): general
  - (m): small to medium-sized databases, and web servers
- Compute Optimized (c): High-performance processing for compute-intensive applications
  - (c): high-performance web servers, batch processing, and gaming servers.
- Memory Optimized (r): Fast performance for workloads processing large datasets in memory
  - (r): high-performance databases, big data analytics, and in-memory caches.
- Storage Optimized (i, d): High, sequential read/write access to large datasets on local storage
  - (i): NoSQL/SQL databases and data warehousing.
- Accelerated Computing (p, g): GPU-based for graphics and machine learning applications
  - (p): ML, AI
- Burstable Performance (t): Cost-effective option for workloads with variable CPU usage

### Security Groups

- Security Groups are the fundamental of network security in AWS
- Security groups only contain allow rules
- Security groups rules can reference by IP or by security group
- They regulate:
  - Access to Ports
  - Authorized IP ranges — IPv4 and IPv6
  - Control of inbound network (from other to the instance)
  - Control of outbound network (from the instance to other)
- Can be attached to multiple instances
- Locked by region
- All inbound traffic is **blocked** by default
- All outbound traffic is **authorized** by default

### EC2 SSH

IMPORTANT: never enter you aws IAM access key and secure key in a EC2 instance,
use IAM roles instead to perform AWS CLI commands.

### EC2 Purchasing Options

- On-Demand Instance — short workload, predictable pricing, pay by second (Windows & Linux) or by hour (Other OS)
- Reserved (1 & 3 years) (Different up front payment options)
  - Reserved Instances — long workloads (locked instance config/attributes)
    - Can sell on the marketplace
    - Regional or Zonal
  - Convertible Reserved Instances — long workloads with flexible (flex config/attributes) instances
- Savings Plans (1 & 3 years) — commitment to an amount of usage ($/hour for x years), long workload
  - Locked to instance family and AWS region
  - Flexible: Instance size, OS and Tenancy
  - Usage beyond plan is billed at the On-Demand price
- Spot Instances — short workloads, cheap, can lose instances (less reliable)

- Dedicated Hosts — book an entire physical server, control instance placement
  - per-socket, per-core, per-VM control to comply with complicated licensing model
    - (Access to the physical server)
  - Purchasing Options: Reserved, On-Demand

- Dedicated Instances — no other customers will share your hardware
  - No control over instance placement
  - May share instances with others in the same account

- Capacity Reservations — reserve On-Demand instances capacity in a specific AZ for any duration
  - No time commitment (create/cancel anytime), no billing discounts
  - Combine with Savings or Regional Reserved instances for discounts

### EC2 Stop Instance

- Max Spot Price vs. Current Spot Price
  - One-time Request: A Spot instance request that is created and terminated once the instance runs.
  - Persistent Request: A Spot instance request that remains active within a specified time range (Valid From and Valid Until) and can be created and terminated multiple times during this period.
- Spot Block (Discontinued)
  - Provides a set duration (1 to 6 hours) of uninterrupted Spot instances. This option is no longer available.

---

- Spot Fleet
  - A collection of Spot Instances, and optionally On-Demand Instances, designed to meet target capacity while adhering to specified price constraints.

- Spot Fleet Strategies
  - Lowest Price: Launches instances from the Spot Pools with the lowest prices.
    - (Minimize cost)
  - Diversified: Distributes instances across multiple Spot Pools to increase availability and reliability.
    - (Maximize availability and reliability)
  - Capacity Optimized: Prioritizes Spot Pools with the most available capacity, reducing the likelihood of interruptions.
    - (Maximize successful instance launches)
  - Price Optimized (recommended): Selects instances by considering both the price and available capacity to optimize costs while reducing the chance of interruptions.
    - (Balance cost and capacity)

### IPs

- Private IP:
  - Not reachable over the internet.
  - Remains associated with the instance even if it is stopped and started again.
- Public IP:
  - Assigned to instances for communication over the internet.
  - Automatically assigned when an instance is launched.
  - Released when the instance is stopped and a new one is assigned when the instance is restarted.
- Elastic IP:
  - A static, public IPv4 address that you can allocate to any instance or ENI in a VPC.
  - Can be associated with any instance in your account.
  - Maintain a consistent IP address after stopping and starting an instance.
  - Remains associated with your account until you release it, even if the instance is stopped.
  - **NOT RECOMMENDED** use Load Balancer or other methods with public IP

### Placement Groups

Control over the EC2 placement strategy

- Cluster Placement Group
  - Objective: Achieve low-latency and high-throughput.
  - Behavior: Launches instances in a single Availability Zone, physically close together in the same rack.
  - Advantages: Ideal for workloads that require high network performance, like HPC (High-Performance Computing) or big data applications.
  - Risks: Limited to a single Availability Zone; if the underlying hardware fails, all instances in the group could be affected.

- Spread Placement Group
  - Objective: Maximize fault tolerance.
  - Behavior: Distributes instances across distinct hardware to minimize correlated failures. Can span multiple Availability Zones.
  - Advantages: Suitable for critical applications that need to be isolated from failures, like HA (High Availability) services.
  - Risks: Limited to seven instances per Availability Zone within a single Spread Placement Group.

- Partition Placement Group
  - Objective: Balance fault tolerance and scalability.
  - Behavior: Divides instances into logical partitions, ensuring that each partition is placed on separate racks, minimizing the impact of hardware failure.
  - Advantages: Scales to hundreds of instances, making it ideal for large distributed and replicated workloads like HDFS, HBase, and Cassandra.
  - Risks: Although it provides high fault tolerance, there’s a potential for increased latency compared to a Cluster Placement Group due to the separation of partitions.

### Elastic Network Interface (ENI)

- Purpose: A virtual network interface that can be attached to an instance in a VPC.
- Use Cases:
  - Attach additional ENIs to an instance for network redundancy.
  - Manage separate security groups and IP addresses.
  - Enable failover by moving ENIs between instances.
- Key Features:
  - Can be detached and reattached to different instances within the same Availability Zone.
  - Supports multiple IP addresses, security groups, and MAC addresses.
  - Elastic Network Interfaces (ENIs) are bounded to a specific AZ.
    - You can not attach an ENI to an EC2 instance in a different AZ.

### EC2 Hibernate

- Hibernate:
  - Saves the instance’s RAM to disk and stops it.
  - Instance state and data are preserved.
  - RAM state is saved to EBS root volume (must have enough space)
  - not supported for bare metal instances
- Stop:
  - Shuts down the instance.
  - Data on the root device persists.
- Terminate:
  - Permanently deletes the instance.
  - Attached storage is deleted unless specified otherwise.

## EC2 Instance Storage


#
#
#
#
#
#
#
#
#
#
#
#
#
#
#

Elastic Load Balancer (ELB)

    Purpose: Distributes incoming application or network traffic across multiple targets, such as EC2 instances, containers, or IP addresses.
    Types:
        Application Load Balancer (ALB): Operates at the application layer (Layer 7), ideal for HTTP/HTTPS traffic and microservices.
        Network Load Balancer (NLB): Operates at the transport layer (Layer 4), suited for ultra-high-performance applications.
        Gateway Load Balancer (GWLB): Simplifies deployment, scaling, and management of third-party virtual appliances.
    Key Features:
        Automatic scaling based on incoming traffic.
        Health checks to ensure only healthy instances receive traffic.
        Integration with Auto Scaling for dynamic scaling.

Elastic Fabric Adapter (EFA)

    Purpose: A network device that you can attach to an EC2 instance to accelerate High-Performance Computing (HPC) and machine learning applications.
    Use Cases:
        Applications that require high throughput and low latency, such as HPC or tightly coupled parallel computing.
    Key Features:
        Bypasses the operating system kernel to provide higher bandwidth and lower latency.
        Supports standard IP networking for compatibility with existing applications.

Elastic Network Adapter (ENA)

    Purpose: Provides high-performance networking for EC2 instances, with support for enhanced networking features.
    Use Cases:
        Applications requiring high throughput, low latency, and reliable connectivity.
    Key Features:
        Supports up to 100 Gbps of network bandwidth on supported instance types.
        Reduces network jitter and latency.