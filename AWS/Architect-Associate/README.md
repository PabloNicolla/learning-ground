# Architect Associate

- [Architect Associate](#architect-associate)
  - [Aws Infrastructure Intro](#aws-infrastructure-intro)
    - [Regions](#regions)
    - [AZ](#az)
  - [Identity and Access Management (IAM)](#identity-and-access-management-iam)
    - [Users \& Groups](#users--groups)
    - [IAM Policies](#iam-policies)
      - [IAM Managed Policy](#iam-managed-policy)
      - [IAM Inline Policy](#iam-inline-policy)
      - [IAM Permissions](#iam-permissions)
      - [IAM policies Structure](#iam-policies-structure)
    - [Aws Access](#aws-access)
      - [AWS SDK](#aws-sdk)
      - [AWS CloudShell](#aws-cloudshell)
    - [Roles For Services](#roles-for-services)
    - [IAM Security Tools](#iam-security-tools)
      - [IAM Credentials Report (account-level)](#iam-credentials-report-account-level)
      - [IAM Access Advisor (user-level)](#iam-access-advisor-user-level)
    - [IAM Guidelines \& Best Practices](#iam-guidelines--best-practices)
  - [EC2 Fundamentals](#ec2-fundamentals)
    - [EC2 sizing \& configuration options](#ec2-sizing--configuration-options)
    - [EC2 Types](#ec2-types)
    - [Security Groups](#security-groups)
    - [EC2 SSH](#ec2-ssh)
    - [EC2 Purchasing Options](#ec2-purchasing-options)
    - [EC2 Stop Instance](#ec2-stop-instance)
    - [IPs](#ips)
    - [Placement Groups](#placement-groups)
    - [Elastic Network Interface (ENI)](#elastic-network-interface-eni)
    - [EC2 Hibernate](#ec2-hibernate)
  - [Elastic Block Store (EBS) \[EC2 Instance Storage\]](#elastic-block-store-ebs-ec2-instance-storage)
    - [EBS Volume Attributes](#ebs-volume-attributes)
    - [EBS Snapshots](#ebs-snapshots)
      - [Archive Tier Snapshots](#archive-tier-snapshots)
      - [Recycle Bin for EBS Snapshots](#recycle-bin-for-ebs-snapshots)
      - [Fast Snapshot Restore (FSR)](#fast-snapshot-restore-fsr)
    - [Amazon Machine Image (AMI)](#amazon-machine-image-ami)
      - [Types of AMIs](#types-of-amis)
      - [Creating an AMI](#creating-an-ami)
    - [EC2 Instance Store](#ec2-instance-store)
    - [EBS volume types](#ebs-volume-types)
      - [SSD-Backed Volumes](#ssd-backed-volumes)
      - [HDD-Backed Volumes](#hdd-backed-volumes)
    - [EBS Multiple Attach](#ebs-multiple-attach)
      - [EBS Use cases](#ebs-use-cases)
      - [Limitations and Considerations](#limitations-and-considerations)
    - [EBS Encryption](#ebs-encryption)
    - [Amazon Elastic File System (EFS)](#amazon-elastic-file-system-efs)
      - [EFS Key Features](#efs-key-features)
      - [EFS Performance Modes](#efs-performance-modes)
      - [EFS Throughput Modes](#efs-throughput-modes)
      - [EFS Storage Classes](#efs-storage-classes)
      - [EFS Backup and Recovery](#efs-backup-and-recovery)
      - [EFS Integration](#efs-integration)
      - [EFS Cost](#efs-cost)
      - [EFS Availability](#efs-availability)
    - [EFS vs EBS](#efs-vs-ebs)
  - [High Availability (HA) and Scalability: (ELB) \& (ASG)](#high-availability-ha-and-scalability-elb--asg)
    - [Elastic Load Balancer (ELB)](#elastic-load-balancer-elb)
      - [ELB Types](#elb-types)
    - [ALP vs NLB vs GWLB](#alp-vs-nlb-vs-gwlb)
    - [Application Load Balancer (ALP)](#application-load-balancer-alp)
    - [Network Load Balancer (NLB)](#network-load-balancer-nlb)
      - [NLB Use Cases Examples](#nlb-use-cases-examples)
    - [Gateway Load Balancer (GWLB)](#gateway-load-balancer-gwlb)
      - [GWLB Use Cases Examples](#gwlb-use-cases-examples)
    - [Sticky Sessions Cookies Names](#sticky-sessions-cookies-names)
    - [Cross-Zone Load Balancing](#cross-zone-load-balancing)
    - [SSL - Server Name Indication (SNI)](#ssl---server-name-indication-sni)
    - [Connection draining ELB](#connection-draining-elb)
    - [Auto Scaling Group (ASG)](#auto-scaling-group-asg)
      - [ASG Scaling Policies](#asg-scaling-policies)
        - [Good Metrics for ASG](#good-metrics-for-asg)
  - [RDS \& AURORA \& ElastiCache](#rds--aurora--elasticache)
    - [Amazon RDS (Relational Database Service)](#amazon-rds-relational-database-service)
      - [RDS Read Replicas](#rds-read-replicas)
      - [Multi-AZ Deployments (Standby instance)](#multi-az-deployments-standby-instance)
    - [RDS Custom](#rds-custom)
    - [Amazon Aurora](#amazon-aurora)
      - [Aurora HA](#aurora-ha)
      - [Aurora Custom Endpoints](#aurora-custom-endpoints)
      - [Aurora Serverless](#aurora-serverless)
      - [Aurora Global](#aurora-global)
    - [RDS Backups](#rds-backups)
      - [Aurora Backups](#aurora-backups)
      - [RDS \& Aurora Restore](#rds--aurora-restore)
      - [Aurora Database Cloning](#aurora-database-cloning)
    - [RDS Security](#rds-security)
    - [Amazon RDS Proxy](#amazon-rds-proxy)
      - [RDS Proxy Use cases examples](#rds-proxy-use-cases-examples)
    - [Amazon ElastiCache](#amazon-elasticache)
      - [ElastiCache Use cases](#elasticache-use-cases)
      - [Redis vs Memcached](#redis-vs-memcached)
      - [ElastiCache Security](#elasticache-security)
      - [Cache Patterns](#cache-patterns)
  - [Ports To Be Familiar With](#ports-to-be-familiar-with)
    - [Common Ports](#common-ports)
    - [Databases Ports](#databases-ports)
  - [Domain Name System (DNS)](#domain-name-system-dns)
  - [Amazon Route 53](#amazon-route-53)
    - [Domain Registration](#domain-registration)
    - [DNS Routing](#dns-routing)
    - [Health Checks and Monitoring](#health-checks-and-monitoring)
    - [Traffic Flow Management](#traffic-flow-management)
    - [Domain Name Management](#domain-name-management)
    - [Security and Compliance](#security-and-compliance)
    - [Integration with Other AWS Services](#integration-with-other-aws-services)
    - [Global Infrastructure](#global-infrastructure)
- [](#)
- [](#-1)
- [](#-2)
- [](#-3)
- [](#-4)
- [](#-5)
- [](#-6)


## Aws Infrastructure Intro

### Regions

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

### IAM Policies

RECOMMENDED: **Least Privilege Principle**

- A policy is a JSON document that defines permissions.
- It specifies what actions are allowed or denied on which resources.
- Policies can be attached to IAM users, groups, or roles to grant them permissions.
- There are two main types of policies: managed policies and inline policies

#### IAM Managed Policy

- Managed policies are standalone policies that can be attached to multiple users, groups, or roles.
- There are two types of managed policies:
  - AWS Managed Policies: Created and managed by AWS. They are designed to provide permissions for common use cases.
  - Customer Managed Policies: Created and managed by the user. They offer more flexibility and customization.

#### IAM Inline Policy

- Inline policies are embedded directly into a specific user, group, or role.
- They maintain a strict one-to-one relationship with the identity they are attached to.
- When the identity is deleted, the inline policy is also deleted.
- Inline policies are useful when you want to ensure that the permissions are not inadvertently assigned to the wrong identity.

#### IAM Permissions

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

### Aws Access

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

### Roles For Services

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

#### EBS Use cases

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

#### EFS Key Features

- AWS manages all aspects of the file system, including scaling, patching, and backups.
- Automatically scales up or down
- Compatible with Linux based AMI
- Pay-per-use

#### EFS Performance Modes

- General Purpose (default):
  - Best for latency-sensitive use cases like web serving, content management, and home directories.
  - Low-latency file operations with up to thousands of concurrent client connections.
- Max I/O:
  - Designed for workloads requiring high levels of throughput, such as big data and analytics, media processing, and genomics analysis.
  - Optimized for higher aggregate throughput but with slightly higher latencies.

#### EFS Throughput Modes

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

#### EFS Storage Classes

- Standard:
  - The default storage class, designed for frequently accessed files.
- Infrequent Access (IA):
  - Lower cost for files that are accessed less frequently, with slightly higher access latency.
  - Automatically moves files to IA if they haven’t been accessed for 30 days.
- Archive:
  - Rarely accessed data (few times a year), 50% cheaper.

User lifetime policies to automatically move files between storage tiers

#### EFS Backup and Recovery

- EFS Backup: Integrated with AWS Backup for automated backups and compliance.
- Durability: EFS is designed for 99.999999999% (11 9's) of durability and 99.99% availability.

#### EFS Integration

- AWS Services: Seamlessly integrates with other AWS services like EC2, Lambda, ECS, and EKS.
- On-Premises Access: EFS can be accessed from on-premises data centers using AWS Direct Connect or VPN.

#### EFS Cost

- Pay-as-you-go pricing based on the storage and throughput you use.
- Cost savings are possible by using the Infrequent Access storage class for less frequently accessed data.

#### EFS Availability

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

### Elastic Load Balancer (ELB)

ELS forward traffic to multiple EC2 instances downstream

- Spread load
- Expose single access point (DNS)
- handle downstream failures
- regular health checks
- single SSL termination (HTTPS) for all downstream instances
- High availability
- Static DNS name

#### ELB Types

- Classic Load Balancer (CLB) - (V1 OLD GENERATION) (DEPRECIATED)
  - HTTP, HTTPS, TCP, SSL (SECURE TLS)
- Application Load Balancer (ALB) - (V2)
  - HTTP, HTTPS, WebSocket
- Network Load Balancer (NLB) - (V2)
  - TCP, TLS (SECURE TCP), UDP
- Gateway Load Balancer (GWLB) - (V2)
  - Layer 3 (Network layer) - IP Protocol

### ALP vs NLB vs GWLB

[Network Layers](../../Network/README.md)

| Feature / Criteria                 | Application Load Balancer (ALB)                               | Network Load Balancer (NLB)                          | Gateway Load Balancer (GWLB)                                    |
| ---------------------------------- | ------------------------------------------------------------- | ---------------------------------------------------- | --------------------------------------------------------------- |
| Layer                              | Layer 7 (Application Layer)                                   | Layer 4 (Transport Layer)                            | Layer 3 (Network Layer)                                         |
| Use Case                           | HTTP/HTTPS traffic, microservices, containerized applications | TCP/UDP traffic, low-latency requirements, static IP | Deploying, scaling, and managing third-party virtual appliances |
| Protocol Support                   | HTTP, HTTPS, WebSockets, (HTTP/2)                             | TCP, UDP, TLS                                        | IP Protocols (e.g., ICMP, IP-in-IP)                             |
| Load Balancing Algorithm           | Round Robin, Least Outstanding Requests                       | Flow Hashing                                         | Hash-based load balancing                                       |
| Sticky Sessions (Session Affinity) | Supported                                                     | Supported                                            | Not Applicable                                                  |
| SSL Termination                    | Supported (SSL offloading)                                    | Supported (SSL passthrough)                          | Not Applicable                                                  |
| Target Types                       | EC2 instances, IP addresses, Lambda functions, containers     | EC2 instances, IP addresses                          | Virtual appliances                                              |
| Health Checks                      | HTTP/HTTPS-based, customizable                                | TCP/HTTP-based, fast & basic                         | ICMP-based                                                      |
| Logging and Monitoring             | Access Logs, CloudWatch metrics                               | Flow Logs, CloudWatch metrics                        | Flow Logs, CloudWatch metrics                                   |
| Pricing                            | Based on LCU (Load Balancer Capacity Units), data processed   | Based on LCU, data processed                         | Based on LCU, data processed                                    |
| Integration with AWS Services      | Deep integration with ECS, EKS, Lambda                        | Integration with VPC, CloudFormation                 | Integration with Firewall Manager, Transit Gateway              |
| Security Features                  | WAF (Web Application Firewall) integration                    | Security Groups, NACLs                               | Stateless or stateful network protection                        |
| Static IP Support                  | Not supported (uses DNS name)                                 | Supported                                            | Supported                                                       |
| Cross-Zone Load Balancing          | Supported                                                     | Supported                                            | Supported                                                       |
| Client IP Preservation             | Default behavior                                              | Preserved by default                                 | Preserved by default                                            |
| Multi-Protocol Support             | No                                                            | Yes (TCP, UDP, TLS)                                  | No                                                              |
| WebSocket Support                  | Supported                                                     | Not supported                                        | Not applicable                                                  |
| Advanced Routing                   | Path-based, host-based, query string, HTTP header             | Not supported                                        | Not applicable                                                  |

### Application Load Balancer (ALP)

- fixed hostname XXX.region.elb.amazonaws.com
- application (downstream instances) do not see the client IP directly
  - Client IP is inserted in the header X-Forwarded-For
  - Port (X-Forwarded-Port)
  - Proto (X-Forwarded-Proto)

### Network Load Balancer (NLB)

- Latency 100ms vs ~400ms for ALB
- Handle million of requests per second
- One static IP per AZ (in addition to the static DNS)

#### NLB Use Cases Examples

1. NLB -> [EC2 instances AWS ID]
2. NLB -> [EC2 instance public IP, sever anywhere in the world public IP]
3. NLB -> [Application Load Balancer]

### Gateway Load Balancer (GWLB)

1. User --(traffic)--> GWLB
2. GWLB --(traffic)--> Target Group (3rd party security virtual appliances)
3. Target Group (3rd party security virtual appliances) --(traffic)--> GWLB
4. GWLB --(traffic)--> Application

GENEVE protocol on port 6081

- Transparent Network Gateway - sing entry/exit for all traffic
- Load Balancer

#### GWLB Use Cases Examples

1. NLB -> [EC2 instances AWS ID]
2. NLB -> [EC2 instance public IP, sever anywhere in the world public IP]

### Sticky Sessions Cookies Names

Avoid cookie names that starts with `AWS`

- Application based Cookies
  - Custom Cookie
    - Generated by the target
  - Application Cookie
    - Generated by the LB
- Duration based Cookies
  - Generated by the LB

### Cross-Zone Load Balancing

- Enabled
  - it distributes load evenly between all downstream even if they are in different AZs
- Disabled
  - distributes incoming load between instances in the same AZ

- Default
  - ALB enabled
  - NLB & GWLB disabled

- Charges
  - ALB no charges for inter AZ data
  - NLB & GWLB pay for inter AZ data

### SSL - Server Name Indication (SNI)

SSL allows in-flight data encryption.

- Multiple SSL certificates for one web server
- Client tells server to find the desired SSL based on the request hostname

SSL Cert 1 -> `www.example1.com`
SSL Cert 2 -> `www.example2.com`

### Connection draining ELB

Ensures that the load balancer stops sending new requests to instances that are de-registering or unhealthy
while allowing existing connections to complete.

- CLB -> Connection draining.
- For ALB & NLB -> connection draining is referred to as deregistration delay.

- Between 1 to 3600 seconds
- Can be disabled

### Auto Scaling Group (ASG)

- Scale out/in automatically depending on the configuration and events such as CloudWatch Alarms
- Scale between max and min capacity configured
- Free, you pay for the resources being used

When configured with a Load Balancer the new instances are automatically added to the LB downstream/redirect group.

- AMI improves the ASG efficiency
- ASG has a cooldown period after scaling up/down (can be changed)

#### ASG Scaling Policies

- Dynamic Scaling:
  - Target Tracking Scaling:
    - E.G AVG CPU must start around 40%
  - Simple / Step Scaling:
    - E.G CloudWatch Alarm (CPU > 70%) add 2 units
    - E.G CloudWatch Alarm (CPU < 30%) remove 1 unit
- Scheduled Scaling:
  - Scale based on schedules
- Predictive Scaling:
  - Scaled Based on ML forecast load

##### Good Metrics for ASG

- CPU
- Request Count
- Network Load
- CloudWatch Metrics

## RDS & AURORA & ElastiCache

### Amazon RDS (Relational Database Service)

- Managed Service: Automates tasks like hardware provisioning, database setup, patching, backups, and scaling.
- Scalability: Allows you to scale your database compute and storage with just a few clicks or API calls.
- Security: Offers encryption at rest and in transit, VPC integration, and IAM-based access control.
- Automatic Backups: Provides automatic backups, database snapshots, and point-in-time recovery.
- Monitoring: Integrated with Amazon CloudWatch for monitoring database performance and setting up alarms.
- Database engines: Amazon Aurora, MySQL, PostgreSQL, MariaDB, Oracle, Microsoft SQL Server, and IBM DB2
- No SSH access

#### RDS Read Replicas

- Purpose: Used for horizontal scaling of read operations. They help to offload read traffic from the primary database, improving performance for read-heavy workloads.
- Replication: **Asynchronously** replicates data from the primary database to one or more read replicas.
- Usage: Primarily for read operations, reporting, and analytics. Write operations must still go through the primary database.
- **Cross-Region Replication**: You can create read replicas in different AWS regions, providing read access across regions and improving latency for global applications.
- Promotion: In the event of an issue with the primary database, a read replica can be manually promoted to a standalone database, but this is not automatic.
- Cost:
  - Read replicas incur additional charges for compute and storage.
  - Same Region is free
  - Different Region replica incur extra fees
- Read Replica can be set to Multi-AZ
- Up to 15 replicas

#### Multi-AZ Deployments (Standby instance)

- Purpose: Provides high availability and failover support for your database. It automatically replicates data to a standby instance in a different Availability Zone (AZ) within the same region.
- Replication: **Synchronously** replicates data between the primary and standby instances.
- Failover: In the event of a failure (e.g., hardware failure, network issue), RDS automatically fails over to the standby instance without manual intervention. This ensures minimal downtime.
- Usage: Ideal for production environments where high availability and automatic failover are critical.
- Read/Write Operations: Both read and write operations are directed to the primary database, with the standby instance only taking over during a failover.
- Zero down time from Single-AZ to multi AZ

### RDS Custom

Managed Oracle and Microsoft SQL Server Databases

- This service grants full admin access to the OS and Database. (SSH access)

It is recommended to stop the instance and take a snapshot before applying new configurations

### Amazon Aurora

- Not open source
- Postgres & MySQL supported
- Cloud optimized
- Storage automatically grows from 10GB up 128TB
- Up to 15 replicas with fast replica lag
- HA native (fast failover recovery)
- More efficient than EDS, but more expensive
- Replicas can be of different sizes (CPU, ...)
- Easy Amazon Machine Learning integration

#### Aurora HA

- 6 copies of data across 3 AZ:
  - 4 copies out of 6 to writes
  - 3 copies out of 6 to reads
  - P2P self healing
  - Storage across hundreds of volumes
- Only Master can do write
- Failover recovery in less than 30s
- All can do reads
- Support for Cross-Region
- Endpoints
  - 1 Reader endpoint
  - 1 Writer endpoint

#### Aurora Custom Endpoints

db.size_3 --(Master)--> Writer endpoint

db.size_3 --(Replica)--> CustomEndpoint_1 endpoint
db.size_3 --(Replica)--> CustomEndpoint_1 endpoint

db.size_6 --(Replica)--> CustomEndpoint_2 endpoint
db.size_6 --(Replica)--> CustomEndpoint_2 endpoint

Instead of a single reader endpoint,
now there are different endpoints for different use cases that require different processing power

#### Aurora Serverless

- Automated init and scaling based on usage
- Good for infrequent, intermittent or unpredictable workloads
- No capacity planning needed
- Pay per second

#### Aurora Global

- 1 Primary Region (read/write)
- up to 5 secondary regions (read) (1s replication lag)
- up to 16 read replicas per secondary region
- Secondary regions can be promoted to Primary (Disaster recovery)

### RDS Backups

- Automated Backups
  - Daily
  - Transaction logs every 5 minutes
  - Restore to any point in time in the timeframe
  - 1 to 35 days retention, set 0 to disable

- Manual DB Snapshot
  - Retention until manual deletion
  - Can be used to save costs by replacing a stopped database

#### Aurora Backups

Backup cannot be disabled

#### RDS & Aurora Restore

- Restore from backup/snapshot
- Restore from S3

#### Aurora Database Cloning

- Uses copy-on-write protocol and is faster than snapshots & restore
- Useful for creating a "dev" DB from prod

### RDS Security

- At-rest encryption
  - Option must be activated on launch time
  - else activate encryption from snapshot
- In-flight encryption
- IAM Authentication
- Security Groups
- Audit logs can be enable

### Amazon RDS Proxy

Similar with PGbouncer, share connections to reduce resource usage

- reduce Aurora & RDS failover
- no code change required (in most cases)
- Autoscaling
- Serverless
- HA (multi-az)
- Support for almost all DBs
- Enforce IAM authentication for DB
- RDS proxy is never public accessible (Access from VPC)

#### RDS Proxy Use cases examples

When working with lambda functions that access DB,
million of requests can appear in a minute,
which would overload the database connection pool.
RDS Proxy solves this

### Amazon ElastiCache

- Managed in-memory databases (Redis, Memcached)
- Helps reduce DB load in intensive read environments
- Helps make application stateless (One "RAM" to rule them all)
- OS maintenance, setup, config, recovery, backup, ... managed by AWS
- Requires application code to be adapted to work with cache-db

#### ElastiCache Use cases

- Store user sessions from applications
- Store query results from DB reads
- Must implement cache invalidation techniques

#### Redis vs Memcached

Summary:

- Redis for HA, data persistency and Set/Sorted-sets
- Memcached for Multi-threaded or simpler applications

Table:

| Feature                | Redis                                                                                                                   | Memcached                                                                                      |
| ---------------------- | ----------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------- |
| Data Structure Support | Supports a wide variety of data structures like strings, hashes, lists, sets, sorted sets, bitmaps, and more.           | Primarily supports string data types (key-value pairs).                                        |
| Persistence            | Offers disk persistence with options for snapshotting (RDB) and append-only file (AOF) logs.                            | No persistence; data is stored in memory only and lost upon reboot.                            |
| Scalability            | Built-in replication (master-slave) and clustering for horizontal scalability.                                          | Supports horizontal scaling through sharding but does not have built-in clustering.            |
| Memory Management      | Efficient memory usage with support for LRU eviction policies and data expiration.                                      | Also supports LRU eviction but lacks advanced memory management features of Redis.             |
| Use Cases              | Suitable for caching, real-time analytics, messaging, session storage, and as a primary database for certain use cases. | Best for simple caching solutions where high-speed data access is critical.                    |
| Complexity             | More complex due to its rich feature set, suitable for advanced use cases.                                              | Simpler and easier to set up, ideal for straightforward caching.                               |
| Performance            | Slightly slower than Memcached in some use cases due to its additional features, but still extremely fast.              | Known for being lightweight and very fast, often faster than Redis for pure caching use cases. |
| Atomic Operations      | Supports atomic operations for all data types.                                                                          | Limited atomic operations mainly for basic increment/decrement operations.                     |
| License                | BSD License (Open Source).                                                                                              | BSD License (Open Source).                                                                     |
| Cluster Support        | Native support for clustering with automatic data partitioning.                                                         | No native clustering; must be handled at the application level.                                |
| Multi-threading        | Single-threaded with the ability to run multiple instances on a single server.                                          | Multi-threaded, which can lead to better performance in some cases.                            |
| Backup & Restore       | Supports backup and restore with RDB and AOF files.                                                                     | No built-in backup and restore functionality.                                                  |
| Language Support       | Wide range of client libraries in multiple programming languages.                                                       | Also has broad language support, but fewer client libraries than Redis.                        |
| Geospatial Indexing    | Supports geospatial data types and operations.                                                                          | No support for geospatial data.                                                                |
| Pub/Sub Messaging      | Built-in support for publish/subscribe messaging.                                                                       | No native support for pub/sub messaging.                                                       |
| Community & Ecosystem  | Large, active community with extensive documentation and third-party tools.                                             | Smaller community and ecosystem compared to Redis.                                             |
| Cost                   | Can be more resource-intensive due to additional features.                                                              | Generally more lightweight and cost-effective for basic caching.                               |

#### ElastiCache Security

- Redis
  - IAM Authentication
  - Password/Username
  - Password/token
  - Security groups
  - SSL

- Memcached
  - SASL-based
  - Password/Username

#### Cache Patterns

- LazyLoading
  - Cache data after read (can become stale)
- Write Trough
  - Add/Update the cache after every DB write (no stale data)
- Session Store
  - Store temporary session data

## Ports To Be Familiar With

### Common Ports

- FTP: 21
- SSH: 22
- SFTP: 22
- HTTP: 80
- HTTPS: 443

- RDP: 3389

### Databases Ports

- Postgres: 5432
- MySQL: 3306
- MariaDB: 3306
- MSSQL: 1433
- Oracle RDS: 1521
- Aurora: 5432 (Postgres), 3306 (MySQL)

## Domain Name System (DNS)

Translate human friendly hostname into machine IP addresses

[DNS](../../DNS/README.md)

## Amazon Route 53

### Domain Registration

- Route 53 allows you to register domain names directly through AWS. It supports a wide range of top-level domains (TLDs) like .com, .org, .net, etc.
- It manages domain settings, such as DNS configuration, domain transfer, and renewal.

### DNS Routing

- Authoritative DNS: Route 53 provides authoritative DNS services, which means it responds to DNS queries for your domain with the correct IP address or other DNS records.
- Routing Policies: Route 53 offers various routing policies to determine how DNS queries are resolved:
  - Simple Routing: Directs traffic to a single resource without any special routing logic. (can return multi-value, but it does not have health checks)
  - Weighted Routing: Distributes traffic across multiple resources based on assigned weights. (0 to exclude or all 0 to ignore weight)
  - Latency-Based Routing: Routes traffic to the resource that provides the lowest latency for the end-user.
  - Failover Routing: Automatically routes traffic to a standby resource if the primary one becomes unavailable.
  - Geolocation Routing: Routes traffic based on the geographic location of the requestor. (must have a default record set)
  - Geo-Proximity Routing: Routes traffic based on the geographic location of resources and users, with optional biasing to favor/hide certain locations.
  - IP-Based Routing: Routing is based on the client's IP address
  - Multi-Value Answer Routing: Returns multiple IP addresses for a query, increasing availability.
    - More secure than Simple Routing since health checks can eliminate unhealthy endpoints from the answer
    - Client chooses the IP randomly

### Health Checks and Monitoring

- **HTTP Health Checks only works for public resources**
- Route 53 can monitor the health of your resources through health checks, ensuring that DNS queries are only routed to healthy endpoints.
- Endpoint Health Checks: Regularly checks the status of your web servers, email servers, and other resources.
- DNS Failover: Automatically reroutes traffic to a healthy resource if a primary resource fails.

- Health Checks can work with the following DNS Routing Policies:
  - Weighted Routing
  - Latency-Based Routing
  - Failover Routing
  - Geolocation Routing
  - Multi-Value Answer Routing

- Health check can monitor:
  - endpoints (e.g. /health), (2xx, 3xx), (can parse first 5120 bytes of response text)
  - other health checks (Parent combines all Child's health checks into one)
  - CloudWatch Alarms (Useful to monitor private resources)

### Traffic Flow Management

- Traffic Flow: An easy-to-use visual editor that allows you to create complex routing configurations combining multiple routing policies. It enables you to manage traffic across multiple AWS regions and optimize performance for global users.

### Domain Name Management

- Hosted Zones: A hosted zone is a container for DNS records for a specific domain. Route 53 supports:
  - public hosted zones (for routing traffic on the internet).
  - private hosted zones (for routing within an Amazon VPC). (similar to K8s services)
- DNS Record Types: Route 53 supports all standard DNS record types, including A, AAAA, CNAME, MX, NS, PTR, SOA, SPF, SRV, and TXT records.
- CNAME VS Route 53 ALIAS
  - CNAME allows a hostname (**Except Root Domain, (Top node)/(Zone Apex)**) to point to any other hostname
  - ALIAS works similar to CNAME except:
    - it allows to use the Root Domain
    - it is can only point to some AWS resources (It does not work with EC2 DNS name)
- You can use 3rd party domains with Route 53. (Create a Public Hosted Zone as update 3rd party Registrar NS(Name Servers))

### Security and Compliance

- DNSSEC (Domain Name System Security Extensions): Route 53 supports DNSSEC for domain signing, providing authenticity and integrity for DNS records.
- IAM Policies: Integrates with AWS Identity and Access Management (IAM) to control access to Route 53 resources.
- Audit Logging: Provides logging of DNS query requests via AWS CloudTrail for monitoring and auditing purposes.

### Integration with Other AWS Services

- Seamless Integration: Route 53 integrates closely with other AWS services like S3, CloudFront, Elastic Load Balancing, and more, facilitating smooth DNS configuration for AWS-hosted applications.
- Private DNS for Amazon VPC: You can create private DNS namespaces within your VPC, allowing Route 53 to resolve DNS queries for resources within the VPC.

### Global Infrastructure

- Highly Available: Route 53 is designed with global redundancy and low-latency query resolution using a global network of DNS servers.
- Scalable: Automatically scales to handle large volumes of DNS queries without user intervention.

#
#
#
#
#
#
#
