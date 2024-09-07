# Hashing

- [Hashing](#hashing)
  - [Why Use a Prime Number?](#why-use-a-prime-number)
  - [Influence of Prime Size](#influence-of-prime-size)
    - [Example](#example)
  - [Prime Numbers and Uniqueness](#prime-numbers-and-uniqueness)

## Why Use a Prime Number?

When designing a custom hash function, we want it to distribute keys (in our case, character frequency arrays) uniformly across the hash table. In other words, we want to minimize collisions—situations where two different keys map to the same hash value.

Using a prime number as part of the hash function helps achieve this goal. Why? Because prime numbers have unique properties that make them ideal for hashing:

- Relatively Uncommon Factors: Prime numbers have very few factors (only 1 and themselves). This property reduces the chance of collisions.
- Spread Across the Range: When we multiply by a prime number, it effectively spreads the values across the entire range of possible hash values. This helps distribute keys more evenly.
- Less Likely to Produce Clusters: Non-prime numbers can create clusters of hash values, leading to more collisions. Primes help avoid such clustering.

## Influence of Prime Size

- The choice of the specific prime number matters. Let’s explore how its size affects the hash:
  - Smaller Primes:
    - Smaller primes (e.g., 2, 3, 5) are efficient for multiplication. They keep the hash computation fast.
    - However, they might lead to more collisions because they don’t spread values as widely.
  - Larger Primes:
    - Larger primes (e.g., 31, 37, 101) provide better distribution.
    - They reduce the chance of collisions but might be slightly slower due to larger multiplications.
    - Common choices include 31 (used in Java’s String.hashCode()) and 37 (used in Python’s dictionary).

### Example

- Let’s say we’re hashing character frequencies (assuming lowercase letters only) with an array freq[26].
- We’ll use a prime like 31.
- Our hash function:

```py
hash_value = 0
for i in range(26):
    hash_value = hash_value * 31 + freq[i]
```

- This ensures that even small changes in the character frequencies lead to distinct hash values.

## Prime Numbers and Uniqueness

- The uniqueness of the hash value depends on the properties of the prime and the input data.
- While prime numbers help reduce collisions, they don’t guarantee absolute uniqueness. Collisions can still occur due to the limited range of hash values.
- However, using a prime minimizes the likelihood of collisions, especially when combined with other techniques (like open addressing or separate chaining).
