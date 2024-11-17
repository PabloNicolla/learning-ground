# GraphQL

- [GraphQL](#graphql)
  - [Introduction](#introduction)
    - [1. **Core Concepts of GraphQL**](#1-core-concepts-of-graphql)
      - [**1.1. Schema and Types**](#11-schema-and-types)
      - [**1.2. Queries**](#12-queries)
      - [**1.3. Mutations**](#13-mutations)
      - [**1.4. Resolvers**](#14-resolvers)
    - [2. **Setting Up a GraphQL Server with TypeScript**](#2-setting-up-a-graphql-server-with-typescript)
      - [**2.1. Installation**](#21-installation)
      - [**2.2. TypeScript Configuration (`tsconfig.json`)**](#22-typescript-configuration-tsconfigjson)
      - [**2.3. Basic Server Setup**](#23-basic-server-setup)
      - [**2.4. Running the Server**](#24-running-the-server)
    - [3. **Advanced GraphQL Features**](#3-advanced-graphql-features)
      - [**3.1. Input Types**](#31-input-types)
      - [**3.2. Fragments**](#32-fragments)
      - [**3.3. Subscriptions**](#33-subscriptions)
    - [4. **Error Handling**](#4-error-handling)
    - [5. **GraphQL with TypeScript Types**](#5-graphql-with-typescript-types)
    - [6. **Comparison: GraphQL vs. REST**](#6-comparison-graphql-vs-rest)
    - [7. **Best Practices**](#7-best-practices)
    - [8. **Conclusion**](#8-conclusion)

## Introduction

GraphQL is a query language for APIs that was developed by Facebook. It offers a more flexible and efficient way of querying data compared to traditional REST APIs. Instead of having multiple endpoints for different resources, a GraphQL API typically exposes a single endpoint. The client can then specify exactly what data it needs using queries, reducing the amount of data transferred and simplifying interactions between the client and server.

Here's an in-depth overview of GraphQL, along with TypeScript snippets for practical understanding.

### 1. **Core Concepts of GraphQL**

#### **1.1. Schema and Types**

A **GraphQL schema** defines the structure of data that a client can query. It specifies what queries and mutations are available, as well as the types of data that can be returned.

**Example**:

```graphql
type User {
  id: ID!
  name: String!
  email: String!
}

type Query {
  getUser(id: ID!): User
}
```

- **`User`** is an object type with fields `id`, `name`, and `email`.
- **`Query`** is a root type defining available queries, like `getUser`.

#### **1.2. Queries**

A **query** is a read operation where clients request specific data.

**Example**:

```graphql
query {
  getUser(id: "123") {
    id
    name
  }
}
```

This request asks for a user's `id` and `name` based on the `id` provided.

#### **1.3. Mutations**

A **mutation** is a write operation that allows you to create, update, or delete data.

**Example**:

```graphql
mutation {
  createUser(name: "John", email: "john@example.com") {
    id
    name
  }
}
```

#### **1.4. Resolvers**

**Resolvers** are functions that handle fetching the data for the defined schema fields.

**Example** in TypeScript:

```typescript
const resolvers = {
  Query: {
    getUser: async (_: any, args: { id: string }) => {
      return await getUserFromDB(args.id);
    },
  },
};
```

### 2. **Setting Up a GraphQL Server with TypeScript**

We'll use **Apollo Server** (a popular GraphQL server implementation) and **TypeScript**.

#### **2.1. Installation**

```bash
npm install apollo-server graphql typescript @types/node
```

#### **2.2. TypeScript Configuration (`tsconfig.json`)**

```json
{
  "compilerOptions": {
    "target": "ES6",
    "module": "commonjs",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true
  }
}
```

#### **2.3. Basic Server Setup**

**`schema.ts`**

```typescript
import { gql } from "apollo-server";

export const typeDefs = gql`
  type User {
    id: ID!
    name: String!
    email: String!
  }

  type Query {
    getUser(id: ID!): User
  }

  type Mutation {
    createUser(name: String!, email: String!): User
  }
`;
```

**`resolvers.ts`**

```typescript
import { v4 as uuidv4 } from "uuid";

interface User {
  id: string;
  name: string;
  email: string;
}

const users: User[] = [];

export const resolvers = {
  Query: {
    getUser: (_: any, { id }: { id: string }) => {
      return users.find((user) => user.id === id);
    },
  },
  Mutation: {
    createUser: (_: any, { name, email }: { name: string; email: string }) => {
      const newUser = { id: uuidv4(), name, email };
      users.push(newUser);
      return newUser;
    },
  },
};
```

**`server.ts`**

```typescript
import { ApolloServer } from "apollo-server";
import { typeDefs } from "./schema";
import { resolvers } from "./resolvers";

const server = new ApolloServer({ typeDefs, resolvers });

server.listen().then(({ url }) => {
  console.log(`Server ready at ${url}`);
});
```

#### **2.4. Running the Server**

```bash
npx ts-node server.ts
```

### 3. **Advanced GraphQL Features**

#### **3.1. Input Types**

**Input types** are used in mutations to pass complex objects as arguments.

**Example**:

```graphql
input CreateUserInput {
  name: String!
  email: String!
}

type Mutation {
  createUser(input: CreateUserInput): User
}
```

**Resolver in TypeScript**:

```typescript
createUser: (_: any, { input }: { input: { name: string; email: string } }) => {
  const newUser = { id: uuidv4(), ...input };
  users.push(newUser);
  return newUser;
};
```

#### **3.2. Fragments**

**Fragments** allow you to reuse parts of queries.

**Example**:

```graphql
fragment UserInfo on User {
  id
  name
}

query {
  getUser(id: "123") {
    ...UserInfo
  }
}
```

#### **3.3. Subscriptions**

**Subscriptions** allow real-time updates. For instance, you can notify clients when a new user is created.

```graphql
type Subscription {
  userCreated: User
}
```

**Resolver Example**:

```typescript
import { PubSub } from "apollo-server";
const pubsub = new PubSub();

createUser: async (_: any, { input }: { input: { name: string; email: string } }) => {
  const newUser = { id: uuidv4(), ...input };
  users.push(newUser);
  await pubsub.publish("USER_CREATED", { userCreated: newUser });
  return newUser;
},

Subscription: {
  userCreated: {
    subscribe: () => pubsub.asyncIterator("USER_CREATED"),
  },
},
```

### 4. **Error Handling**

GraphQL includes error messages directly in the response:

```typescript
getUser: (_: any, { id }: { id: string }) => {
  const user = users.find((user) => user.id === id);
  if (!user) {
    throw new Error("User not found");
  }
  return user;
}
```

Client Response:

```json
{
  "data": null,
  "errors": [
    {
      "message": "User not found",
      "locations": [{ "line": 2, "column": 3 }],
      "path": ["getUser"]
    }
  ]
}
```

### 5. **GraphQL with TypeScript Types**

With TypeScript, you can define types to match GraphQL types.

```typescript
type CreateUserInput = {
  name: string;
  email: string;
};

type User = {
  id: string;
  name: string;
  email: string;
};

type Resolvers = {
  Query: {
    getUser: (parent: any, args: { id: string }) => User | undefined;
  };
  Mutation: {
    createUser: (parent: any, args: { input: CreateUserInput }) => User;
  };
};
```

### 6. **Comparison: GraphQL vs. REST**

| Feature            | REST                   | GraphQL                |
| ------------------ | ---------------------- | ---------------------- |
| **Data Fetching**  | Multiple endpoints     | Single endpoint        |
| **Data Shape**     | Fixed by server        | Defined by client      |
| **Over-fetching**  | Common                 | Avoided                |
| **Under-fetching** | Possible               | Avoided                |
| **Versioning**     | Requires new endpoints | No versioning required |

### 7. **Best Practices**

1. **Define Schema Clearly**: Use descriptive field and type names.
2. **Pagination**: Implement pagination for large datasets to prevent over-fetching.
3. **Caching**: Use `@apollo/client` with normalized caching or tools like `dataloader`.
4. **Security**:
   - **Input Validation**: Validate inputs in resolvers.
   - **Authorization**: Implement middleware to check permissions.
5. **Error Handling**: Use `graphql-errors` to format and handle errors.

### 8. **Conclusion**

GraphQL offers a powerful way to interact with APIs by providing flexibility and efficiency compared to REST. The ability to query only what is needed, along with strong typing, makes it a great choice for modern applications, especially when used in conjunction with TypeScript.

This overview should give you a good starting point to dive deeper into GraphQL development. Let me know if you need further exploration into specific areas like **subscriptions**, **caching**, or **performance optimization**.
