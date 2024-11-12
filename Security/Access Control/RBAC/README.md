# Role-Based Access Control (RBAC)

- [Role-Based Access Control (RBAC)](#role-based-access-control-rbac)
  - [Useful links](#useful-links)
  - [Introduction](#introduction)
  - [Key Concepts of RBAC](#key-concepts-of-rbac)
  - [Step 1: Define Types for Users, Roles, and Permissions](#step-1-define-types-for-users-roles-and-permissions)
  - [Step 2: Define Role-Based Permissions](#step-2-define-role-based-permissions)
  - [Step 3: Check User Permissions](#step-3-check-user-permissions)
  - [Step 4: Example Usage](#step-4-example-usage)
  - [Step 5: Adding Role Hierarchies (Optional)](#step-5-adding-role-hierarchies-optional)
    - [Example with Role Hierarchies](#example-with-role-hierarchies)
  - [Benefits of RBAC](#benefits-of-rbac)
  - [Summary](#summary)

## Useful links

[Permissions Video](https://www.youtube.com/watch?v=5GG-VUvruzE)

## Introduction

Role-Based Access Control (RBAC) is a system for managing permissions in a structured, role-centered way, where access rights are assigned based on roles rather than individual users. This helps to simplify and centralize the management of access permissions, making it more scalable, secure, and easy to manage.

## Key Concepts of RBAC

1. **Roles**: A role is a collection of permissions that defines what actions or resources are accessible. Examples of roles might include "Admin," "Editor," or "Viewer."

2. **Permissions**: Permissions define what actions can be performed on resources, such as "read," "write," "update," and "delete."

3. **Users**: Users are assigned roles, which then grant them the relevant permissions. In RBAC, users cannot directly access resources but only access them through the roles they are assigned.

4. **Role Hierarchies**: In some systems, roles can inherit permissions from other roles. For example, a "Manager" role may inherit all permissions of a "User" role and add more permissions on top.

5. **Constraints**: Constraints allow you to restrict the conditions under which roles and permissions apply. For instance, you may only allow certain actions during business hours or restrict access to users from a particular department.

6. **Session**: When a user logs in, an active session can be used to manage temporary permissions that align with the roles assigned to them.

RBAC is implemented in many applications, especially in enterprise environments, where security and access control are vital. Below, we’ll explore how you could implement RBAC in a TypeScript application.

## Step 1: Define Types for Users, Roles, and Permissions

Let's define types for roles, permissions, and users:

```typescript
// Define Permission and Role types
type Permission = 'READ' | 'WRITE' | 'DELETE';
type Role = 'ADMIN' | 'EDITOR' | 'VIEWER';

// Define a User type with roles
interface User {
    id: number;
    name: string;
    roles: Role[];
}
```

## Step 2: Define Role-Based Permissions

Next, let's define the permissions associated with each role in our system. We can store these in a map where each role has a list of allowed permissions.

```typescript
// Map roles to permissions
const rolePermissions: Record<Role, Permission[]> = {
    ADMIN: ['READ', 'WRITE', 'DELETE'],
    EDITOR: ['READ', 'WRITE'],
    VIEWER: ['READ']
};
```

## Step 3: Check User Permissions

We’ll write a helper function to check if a user has a specific permission based on their roles. This function will take in a user and a permission and return `true` or `false` depending on whether the user has that permission.

```typescript
// Function to check if a user has a specific permission
function hasPermission(user: User, permission: Permission): boolean {
    // Loop through each role the user has
    for (const role of user.roles) {
        // Check if the role has the specified permission
        if (rolePermissions[role].includes(permission)) {
            return true;
        }
    }
    return false;
}
```

## Step 4: Example Usage

Now, let’s look at how you might use this function to check user permissions in an application.

```typescript
// Example users
const user1: User = { id: 1, name: 'Alice', roles: ['ADMIN'] };
const user2: User = { id: 2, name: 'Bob', roles: ['VIEWER'] };

// Check if users have 'WRITE' permission
console.log(`Does ${user1.name} have WRITE permission?`, hasPermission(user1, 'WRITE')); // true
console.log(`Does ${user2.name} have WRITE permission?`, hasPermission(user2, 'WRITE')); // false
```

In this example, `user1` has the `ADMIN` role, which includes the `WRITE` permission, so the function returns `true`. `user2`, on the other hand, only has the `VIEWER` role, so they don’t have `WRITE` permission, and the function returns `false`.

## Step 5: Adding Role Hierarchies (Optional)

In larger applications, roles often have hierarchies (e.g., an "Admin" role might inherit permissions from an "Editor" role). Let’s add an example to demonstrate how we might handle this with TypeScript.

```typescript
// Define role hierarchy (optional)
const roleHierarchy: Record<Role, Role[]> = {
    ADMIN: ['EDITOR', 'VIEWER'],
    EDITOR: ['VIEWER'],
    VIEWER: []
};

// Helper function to get all permissions, including inherited
function getAllPermissionsForRole(role: Role): Permission[] {
    const permissions = new Set<Permission>(rolePermissions[role]);
    const inheritedRoles = roleHierarchy[role];

    for (const inheritedRole of inheritedRoles) {
        rolePermissions[inheritedRole].forEach((perm) => permissions.add(perm));
    }
    
    return Array.from(permissions);
}

// Update hasPermission function to include role hierarchy
function hasPermissionWithHierarchy(user: User, permission: Permission): boolean {
    for (const role of user.roles) {
        if (getAllPermissionsForRole(role).includes(permission)) {
            return true;
        }
    }
    return false;
}
```

This function leverages the `roleHierarchy` to recursively fetch permissions for a given role, including those inherited from other roles.

### Example with Role Hierarchies

Using this updated function:

```typescript
const user3: User = { id: 3, name: 'Charlie', roles: ['EDITOR'] };

console.log(`Does ${user3.name} have READ permission?`, hasPermissionWithHierarchy(user3, 'READ'));  // true
console.log(`Does ${user3.name} have DELETE permission?`, hasPermissionWithHierarchy(user3, 'DELETE'));  // false
```

Since `user3` has the "EDITOR" role, they can "READ" (as inherited from "VIEWER") but cannot "DELETE."

## Benefits of RBAC

- **Simplicity and Scalability**: Assigning roles is easier than setting individual permissions, especially as the number of users grows.
- **Improved Security**: Reduces risk of over-permissioned accounts and limits access based on roles.
- **Compliance and Auditability**: Easier to verify that users have the correct permissions and track who has access to what resources.

## Summary

RBAC is an effective model for managing permissions, especially in systems where access control is essential. With TypeScript, you can implement a robust RBAC system that supports direct permission checking, role hierarchies, and is easy to scale and maintain. This modular and layered approach helps ensure that your application’s access control system remains both secure and adaptable as requirements evolve.
