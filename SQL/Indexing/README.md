# Indexing

- [Indexing](#indexing)
  - [TL;DR](#tldr)
  - [Difference Between Single-Column and Composite (Tuple) Indexes](#difference-between-single-column-and-composite-tuple-indexes)
    - [Single-Column Index](#single-column-index)
    - [Composite (Tuple) Index](#composite-tuple-index)
    - [Choosing Between Single-Column and Composite Indexes](#choosing-between-single-column-and-composite-indexes)
    - [Example in Practice](#example-in-practice)
  - [Notes](#notes)

## TL;DR

> [!IMPORTANT]
> Order matters

- Index on (A):
  - The index is most effective for queries that:
    - filter or sort based on A.

- Composite Index on (A, B):
  - The index is most effective for queries that:
    - Use A alone.
    - Use both A and B together.
    - Use A and possibly sort by B.
  - The index is less effective (or may not be used) for queries that:
    - Use only B.

## Difference Between Single-Column and Composite (Tuple) Indexes

### Single-Column Index

- An index on a single column is designed to speed up queries that filter or sort based on that one column.
- Example:

```sql
CREATE INDEX idx_customer_id ON orders (customer_id);
```

This index is used when you have queries like:

```sql
SELECT * FROM orders WHERE customer_id = 123;
```

- The database can quickly locate rows where `customer_id` matches the specified value.

### Composite (Tuple) Index

A composite index (also known as a multi-column index) is created on two or more columns. It's designed to speed up queries that involve filtering, sorting, or joining on multiple columns together.
Example:

```sql
CREATE INDEX idx_customer_order ON orders (customer_id, order_date);
```

This index is useful for queries like:

```sql
SELECT * FROM orders WHERE customer_id = 123 AND order_date = '2023-08-26';
```

The database can efficiently locate rows where both `customer_id` and `order_date` match the specified values.

How to Use a Composite (Tuple) Index

- Order of Columns Matters:
  - The order in which you define columns in a composite index is crucial. The index is most effective for queries that use the leftmost columns in the index.
  - For example, if you create an index on `(customer_id, order_date)`, the index will be used for queries that:
    - Use `customer_id` alone.
    - Use both `customer_id` and `order_date` together.
  - However, it won't be as effective for queries that only use `order_date` without `customer_id`.

- Query Examples:
  - Given an index on `(customer_id, order_date)`, these queries will benefit from the index:

```sql
SELECT * FROM orders WHERE customer_id = 123;
SELECT * FROM orders WHERE customer_id = 123 AND order_date = '2023-08-26';
SELECT * FROM orders WHERE customer_id = 123 ORDER BY order_date;
```

But this query will not benefit as much:

```sql
SELECT * FROM orders WHERE order_date = '2023-08-26';
```

For this, a separate index on `order_date` might be more effective.

### Choosing Between Single-Column and Composite Indexes

- Single-Column Index: Use when queries often filter, sort, or join on a single column.
- Composite Index: Use when queries often involve filtering, sorting, or joining on multiple columns together.

### Example in Practice

Consider a table orders with columns `customer_id`, `order_date`, and `product_id`. If you often query based on both `customer_id` and `order_date`, a composite index on `(customer_id, order_date)` would be beneficial.

**Single-column indexes:**

```sql
CREATE INDEX idx_customer_id ON orders (customer_id);
CREATE INDEX idx_order_date ON orders (order_date);
```

Use these if your queries usually filter by either `customer_id` or `order_date` independently.

**Composite index:**

```sql
CREATE INDEX idx_customer_order ON orders (customer_id, order_date);
```

Use this if your queries frequently filter by both `customer_id` and `order_date` together.

In summary, composite indexes are powerful for optimizing multi-column queries, but it's important to carefully consider the order of columns and the typical query patterns to get the most benefit.

## Notes

- Order Matters: The order of the columns in the index definition matters. Queries that match the prefix of the index (i.e., the first column or the first few columns in the index) will benefit from the index.
- Index Usage: The database engine will use the index for queries where the columns are involved in WHERE, ORDER BY, or join conditions. However, the effectiveness of the index depends on the specific query.
