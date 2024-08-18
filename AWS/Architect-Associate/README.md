# Architect Associate

## AWS INFRASTRUCTURE INTRO

### REGIONS

A geographical area that contains multiple, isolated locations known as Availability Zones.

### AZ

- A physically separate location within a Region.
- Independent power, cooling, and networking to provide high availability and fault tolerance.
- Connected through low-latency, high-bandwidth networks.

## Identity and Access Management (IAM)

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

## Elastic Block Store (EBS) [EC2 Instance Storage]

- Network-Attached Storage: EBS is a network drive that can be attached or detached from running EC2 instances.
- Persistent Storage: Data on EBS volumes persists even after the associated instance is terminated.
- Single Instance Attachment: EBS volumes can only be mounted to one instance at a time.
- Multiple Volumes: An EC2 instance can have multiple EBS volumes attached.
- Availability Zone (AZ) Bound: EBS volumes can only be attached to instances within the same availability zone.
- Latency Considerations: Some latency is expected since the storage is network-attached, not physically attached.

### EBS Volume Attributes

- Size: Measured in GBs.
- IOPS: Input/output operations per second.
- Root Volume Deletion: The root EBS volume is deleted by default when the instance is terminated.
- Additional Volumes: Other EBS volumes are not deleted by default and require manual deletion or configuration.
- Customization: Volume attributes can be modified through the AWS CLI or AWS Console.

### EBS Snapshots

- Cross-AZ Movement: Snapshots allow you to move volumes across availability zones.
- Best Practice: It is recommended to take snapshots of detached EBS volumes to ensure data consistency.

#### Archive Tier Snapshots

- Cost Efficiency: Archive tier is up to 75% cheaper than standard storage.
- Restoration Time: Restoring from the archive tier can take between 24 and 72 hours.

#### Recycle Bin for EBS Snapshots

- Accidental Deletion Protection: A policy can be set up to retain deleted snapshots, protecting against accidental deletion.
- Retention Period: The retention period can range from 1 day to 1 year.

#### Fast Snapshot Restore (FSR)

- Improved Performance: Paying extra enables faster initialization of snapshots, reducing the time to restore them.

### Amazon Machine Image (AMI)

- Definition: An AMI is a pre-configured virtual machine image that includes the operating system, application server, and applications used to launch an EC2 instance.
- Faster boot
- Region bound but can be copied across regions

- Components: An AMI includes the following components:
  - Root Volume Template: Specifies the OS and application environment.
  - Launch Permissions: Controls which AWS accounts can use the AMI to launch instances.
  - Block Device Mapping: Specifies the storage volumes to attach to an instance when it's launched.

#### Types of AMIs

- Public AMIs:
  - Provided by AWS or third parties.
  - Available to all AWS customers.

- Private AMIs:
  - Created by you or shared with specific AWS accounts.
  - Used for custom configurations or sensitive applications.

- Marketplace AMIs:
  - Provided by third-party vendors in the AWS Marketplace.
  - Usually pre-configured with commercial software.

#### Creating an AMI

- From an EC2 Instance: You can create an AMI from an existing EC2 instance by capturing the instance's configuration, including installed software and settings.
- From a Snapshot: You can create an AMI from EBS snapshots, providing more control over the AMI's content.
- Manual Configuration: Specify configurations manually for custom requirements.

### EC2 Instance Store

- EBS volumes have limited performance because they are attached over the network
- **EC2 Instance Store** have disk attached directly to it
  - Higher performance (I/O)
  - Deleted when EC2 instance is stopped
  - Not good for long storage

### EBS volume types

| Volume Type | Use Case                                      | Size            | Max IOPS       | Max Throughput | Durability (SLA) | Cost     |
| ----------- | --------------------------------------------- | --------------- | -------------- | -------------- | ---------------- | -------- |
| gp3/2       | General-purpose workloads                     | 1 GiB - 16TiB   | 16,000         | 1,000 MB/s     | Standard         | Moderate |
| io2         | High-performance, mission-critical workloads  | 4 GiB - 64TiB   | 256,000        | 4,000 MB/s     | 99.999%          | High     |
| io1         | High-performance, latency-sensitive workloads | 4 GiB - 16TiB   | 64,000 (Nitro) | 1,000 MB/s     | 99.9%            | High     |
| st1         | Big data, large sequential workloads          | 125 GiB - 16TiB | 500 IOPS       | 500 MB/s       | Standard         | Low      |
| sc1         | Infrequently accessed data                    | 125 GiB - 16TiB | 250 IOPS       | 250 MB/s       | Standard         | Lowest   |

#### SSD-Backed Volumes

> [!IMPORTANT]
> **CAN BE USER AS EC2 ROOT VOLUME**

- General Purpose SSD (gp2)
  - Size and IOPs are linked.
- General Purpose SSD (gp3)
  - Offers the ability to independently scale IOPS and throughput without increasing the storage size.
- Provisioned IOPS SSD (io2)
- Provisioned IOPS SSD (io1)
  - IOPS: 64,000 (EC2 Nitro), 32,000 (Others)

#### HDD-Backed Volumes

> [!IMPORTANT]
> **CANNOT BE USER AS EC2 ROOT VOLUME**

- Throughput Optimized HDD (st1)
- Cold HDD (sc1)

### EBS Multiple Attach

- io1 and io2 family can be attache to multiple EC2 instances in the same AZ (**AZ bound**)
- Instances have full read & write performance
- Up to 16 EC2 instances at a time

#### Use cases

- High-Performance Computing (HPC): Applications that require shared access to large datasets.
- Clustered Databases: Databases like Oracle RAC that need shared storage across multiple instances.
- File Systems: Clustered or parallel file systems that distribute I/O across multiple instances.

#### Limitations and Considerations

- Data Consistency:
  - Applications must manage data consistency
  - Not all file systems support concurrent access. (File system must be cluster-aware)
- Performance Overhead: Sharing a volume across instances can introduce performance overhead
- There are no additional charges for using Multi-Attach, but the underlying io1 or io2 volumes may incur higher costs due to their provisioned IOPS.

### EBS Encryption

AWS EBS encryption provides data-at-rest encryption for EBS volumes and snapshots.

- Encryption uses AWS Key Management Service (KMS) to manage encryption keys.
- It can be enabled by default for all new EBS volumes and snapshots in a region.
- Encryption occurs on the servers hosting EC2 instances, ensuring encrypted data in-transit between EC2 instances and EBS storage.
- There's no direct way to encrypt an existing unencrypted volume.
  - You need to create a snapshot,
  - encrypt it,
  - and then create a new volume from the encrypted snapshot.
- Encrypted volumes automatically encrypt all data moving between the volume and the instance, snapshots of the volume, and volumes created from those snapshots.
- There's no significant performance impact when using encrypted volumes.

### Amazon Elastic File System (EFS)

- A scalable, fully-managed, cloud-native file storage service that provides a file system for use with AWS Cloud services and on-premises resources.
- Allows multiple EC2 instances to access the same file system concurrently, making it ideal for applications that require shared file storage.
- Works across AZs
- Use cases: content management, web serving, data sharing, Wordpress

#### Key Features

- AWS manages all aspects of the file system, including scaling, patching, and backups.
- Automatically scales up or down
- Compatible with Linux based AMI
- Pay-per-use

#### Performance Modes

- General Purpose (default):
  - Best for latency-sensitive use cases like web serving, content management, and home directories.
  - Low-latency file operations with up to thousands of concurrent client connections.
- Max I/O:
  - Designed for workloads requiring high levels of throughput, such as big data and analytics, media processing, and genomics analysis.
  - Optimized for higher aggregate throughput but with slightly higher latencies.

#### Throughput Modes

- Bursting Throughput (default)
  - Throughput scales with file system size
  - Suitable for most general-purpose workloads
- Provisioned Throughput
  - Allows you to specify throughput independent of storage size
  - Useful for applications requiring higher throughput than the Bursting mode provides
- Elastic Throughput
  - Automatically scales throughput up or down based on workload
  - Eliminates the need to provision throughput in advance
  - Ideal for unpredictable workloads

#### Storage Classes

- Standard:
  - The default storage class, designed for frequently accessed files.
- Infrequent Access (IA):
  - Lower cost for files that are accessed less frequently, with slightly higher access latency.
  - Automatically moves files to IA if they haven’t been accessed for 30 days.
- Archive:
  - Rarely accessed data (few times a year), 50% cheaper.

User lifetime policies to automatically move files between storage tiers

#### Backup and Recovery

- EFS Backup: Integrated with AWS Backup for automated backups and compliance.
- Durability: EFS is designed for 99.999999999% (11 9's) of durability and 99.99% availability.

#### Integration

- AWS Services: Seamlessly integrates with other AWS services like EC2, Lambda, ECS, and EKS.
- On-Premises Access: EFS can be accessed from on-premises data centers using AWS Direct Connect or VPN.

#### Cost

- Pay-as-you-go pricing based on the storage and throughput you use.
- Cost savings are possible by using the Infrequent Access storage class for less frequently accessed data.

#### Availability

- Standard: Multi-AZ: good for production
- One Zone: One AZ: good for dev

### EFS vs EBS

| Feature               | Amazon EBS                             | Amazon EFS                            |
| --------------------- | -------------------------------------- | ------------------------------------- |
| **Storage Type**      | Block Storage                          | File Storage                          |
| **Usage**             | Single EC2 instance                    | Multiple EC2 instances                |
| **Performance Modes** | gp3, io2, io1, st1, sc1                | General Purpose, Max I/O              |
| **Scalability**       | Fixed size, must be manually resized   | Automatically scales with data        |
| **Access**            | Attached to one EC2 instance at a time | Accessible by multiple EC2 instances  |
| **File System**       | Must be formatted with a file system   | POSIX-compliant, NFS-based            |
| **Backup**            | Snapshots                              | AWS Backup integration                |
| **Cost Model**        | Pay per provisioned size and IOPS      | Pay per used storage                  |
| **Latency**           | Low latency                            | Slightly higher latency than EBS      |
| **Use Cases**         | Databases, boot volumes, applications  | Shared file storage, web serving, CMS |
| **Durability**        | 99.999% to 99.999999999% (11 9's)      | 99.999999999% (11 9's)                |
| **Availability**      | 99.9% - 99.99% SLA                     | 99.99% SLA                            |
| **Encryption**        | Data at rest and in transit            | Data at rest and in transit           |
| **Access Control**    | IAM Policies, Security Groups          | IAM Policies, POSIX Permissions       |
| **Cross-AZ Support**  | Snapshots can be copied across AZs     | Accessible within the same region     |
| **Setup Complexity**  | Requires manual setup for scaling      | Automatically managed by AWS          |

## High Availability (HA) and Scalability: (ELB) & (ASG)

Elastic Load Balancer (ELB)

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