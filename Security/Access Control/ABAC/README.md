# Attribute-Based Access Control (ABAC)

- [Attribute-Based Access Control (ABAC)](#attribute-based-access-control-abac)
  - [Useful links](#useful-links)
  - [Introduction](#introduction)
    - [Key Components of ABAC](#key-components-of-abac)
    - [Basic Structure of ABAC Policy Evaluation in TypeScript](#basic-structure-of-abac-policy-evaluation-in-typescript)
      - [Defining Attributes and Policies](#defining-attributes-and-policies)
      - [Creating a Policy and Evaluating Attributes](#creating-a-policy-and-evaluating-attributes)
      - [Sample Policy and Access Request Evaluation](#sample-policy-and-access-request-evaluation)
    - [Advanced Considerations for ABAC](#advanced-considerations-for-abac)
    - [Summary](#summary)

## Useful links

[Permissions Video](https://www.youtube.com/watch?v=5GG-VUvruzE)

## Introduction

Attribute-Based Access Control (ABAC) is an advanced access control model that manages permissions by evaluating a range of attributes related to users, resources, actions, and the environment. Unlike simpler models like Role-Based Access Control (RBAC), ABAC is highly flexible and can support complex policies that incorporate contextual factors. This makes it especially suitable for dynamic environments where traditional role hierarchies are insufficient for nuanced access control.

In ABAC, decisions to grant or deny access depend on whether specific attributes meet the defined policies. Here's a structured look at the main components, features, and benefits of ABAC, along with TypeScript snippets for practical implementation.

---

### Key Components of ABAC

1. **Attributes**:
   - **Subject attributes**: Characteristics of the entity requesting access, such as the user’s role, department, security clearance, or location.
   - **Resource attributes**: Characteristics of the resource being accessed, such as its type, sensitivity level, or owner.
   - **Action attributes**: The type of action the user wants to perform, like "read," "write," "delete," etc.
   - **Environment attributes**: Contextual information about the environment, like the time of day, IP address, device type, or location.

2. **Policies**:
   - Policies in ABAC define which attributes must be matched for access to be granted or denied. Policies are typically written in a structured language, often in JSON or XML, and follow rules that combine these attributes to evaluate permissions.

3. **Policy Enforcement Point (PEP)**:
   - The component that enforces access control by interacting with the user or application trying to access a resource.

4. **Policy Decision Point (PDP)**:
   - The component responsible for making access decisions based on the policies. The PDP evaluates attributes against policies and returns a decision to the PEP.

---

### Basic Structure of ABAC Policy Evaluation in TypeScript

Let's look at some code that demonstrates how you might set up ABAC with TypeScript.

#### Defining Attributes and Policies

We’ll start by defining interfaces for our attributes and a sample policy schema.

```typescript
// Define Subject (User) attributes
interface SubjectAttributes {
  role: string;
  department: string;
  location: string;
  clearanceLevel: number;
}

// Define Resource attributes
interface ResourceAttributes {
  type: string;
  sensitivityLevel: number;
  owner: string;
}

// Define Action attributes
interface ActionAttributes {
  type: string;  // e.g., "read", "write", "delete"
}

// Define Environment attributes
interface EnvironmentAttributes {
  timeOfDay: string; // e.g., "day", "night"
  location: string;
}

// A policy rule example
interface Policy {
  subject: Partial<SubjectAttributes>;
  resource: Partial<ResourceAttributes>;
  action: Partial<ActionAttributes>;
  environment: Partial<EnvironmentAttributes>;
  effect: "allow" | "deny";
}
```

#### Creating a Policy and Evaluating Attributes

Now, let’s define a function to check if an access request matches a policy.

```typescript
// Sample Policy Evaluation Function
function evaluatePolicy(
  policy: Policy,
  subject: SubjectAttributes,
  resource: ResourceAttributes,
  action: ActionAttributes,
  environment: EnvironmentAttributes
): boolean {
  // Check each attribute type to see if it matches the policy
  const subjectMatches = Object.keys(policy.subject).every(key =>
    policy.subject[key as keyof SubjectAttributes] === subject[key as keyof SubjectAttributes]
  );

  const resourceMatches = Object.keys(policy.resource).every(key =>
    policy.resource[key as keyof ResourceAttributes] === resource[key as keyof ResourceAttributes]
  );

  const actionMatches = Object.keys(policy.action).every(key =>
    policy.action[key as keyof ActionAttributes] === action[key as keyof ActionAttributes]
  );

  const environmentMatches = Object.keys(policy.environment).every(key =>
    policy.environment[key as keyof EnvironmentAttributes] === environment[key as keyof EnvironmentAttributes]
  );

  // All attributes must match for the policy to apply
  return subjectMatches && resourceMatches && actionMatches && environmentMatches;
}
```

#### Sample Policy and Access Request Evaluation

Here’s an example policy, along with an access request that we’ll check against it.

```typescript
// Define a sample policy
const examplePolicy: Policy = {
  subject: { role: "manager", clearanceLevel: 3 },
  resource: { type: "confidential", sensitivityLevel: 3 },
  action: { type: "read" },
  environment: { location: "HQ" },
  effect: "allow",
};

// Sample attributes for a request
const requestSubject: SubjectAttributes = {
  role: "manager",
  department: "finance",
  location: "HQ",
  clearanceLevel: 3,
};

const requestResource: ResourceAttributes = {
  type: "confidential",
  sensitivityLevel: 3,
  owner: "company",
};

const requestAction: ActionAttributes = {
  type: "read",
};

const requestEnvironment: EnvironmentAttributes = {
  timeOfDay: "day",
  location: "HQ",
};

// Evaluate access
const isAllowed = evaluatePolicy(
  examplePolicy,
  requestSubject,
  requestResource,
  requestAction,
  requestEnvironment
);

console.log(isAllowed ? "Access granted" : "Access denied");
```

In this setup:
- The `evaluatePolicy` function iterates through the defined policy attributes and matches them with the access request attributes.
- If all attributes in the request match the attributes specified in the policy, access is granted.

---

### Advanced Considerations for ABAC

1. **Policy Combinations**:
   - Complex access control systems often use multiple policies for a single request. For instance, policies can be combined using logical operators (AND, OR) to allow for more nuanced permissions.

2. **Hierarchical Attribute Inheritance**:
   - For scenarios where attributes need to be inherited (e.g., hierarchical roles or security levels), you might need to enhance the matching function to support attribute hierarchies.

3. **Dynamic Attribute Fetching**:
   - ABAC systems often interact with external databases or identity providers to fetch attributes dynamically. In a TypeScript implementation, you might use asynchronous operations to fetch and apply policies.

4. **Performance Optimization**:
   - ABAC systems may evaluate many policies and attributes for a single request. Efficient caching, policy indexing, and attribute pre-processing can help improve performance, especially in high-traffic applications.

5. **Policy Language**:
   - To handle complex policies, a policy language or expression evaluator (like JSON-based policy structure with condition evaluation) may be implemented to parse and apply rules dynamically.

---

### Summary

ABAC provides a robust, flexible access control model suitable for scenarios where fine-grained permissions are needed. Using TypeScript, you can structure attribute-based checks to allow for granular policy evaluation. With this system, access decisions can adapt based on a wide array of contextual factors, making it ideal for complex applications and environments where traditional role-based access is too limiting.
