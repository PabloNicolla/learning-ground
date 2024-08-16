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

- General Purpose (t3, m5): Balanced compute, memory, and networking for diverse workloads
- Compute Optimized (c5): High-performance processing for compute-intensive applications
- Memory Optimized (r5): Fast performance for workloads processing large datasets in memory
- Storage Optimized (i3, d2): High, sequential read/write access to large datasets on local storage
- Accelerated Computing (p3, g4): GPU-based for graphics and machine learning applications
- Burstable Performance (t3): Cost-effective option for workloads with variable CPU usage

### Security Groups & Classic Ports

### EC2 SSH

### EC2 Spot Instances

###

###

###

#

#