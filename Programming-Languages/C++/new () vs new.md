# Placement new() versus Operator new

## Operator new

```cpp
int* a = new int{1}
```

This is the standard dynamic allocation of an integer:

- It allocates memory on the heap for an int.
- It initializes that memory with the value 1.
- It returns a pointer to the newly allocated memory.
- The pointer is stored in the variable a.
- The memory must be manually deallocated using delete when no longer needed.

## Placement new()

```cpp
new(&myInt) int{1}
```

This is called placement new:

- It doesn't allocate new memory.
- It constructs an int object at the memory address of myInt.
- The existing memory at &myInt is overwritten with the value 1.
- It doesn't return a pointer.
- The memory is not deallocated with delete since it wasn't allocated by this operation.

## Key differences

1. Memory allocation:
   - Standard new allocates new memory.
   - Placement new uses existing memory.
2. Return value:
   - Standard new returns a pointer.
   - Placement new doesn't return anything.
3. Deallocation:
   - Memory allocated with standard new must be freed with delete.
   - Placement new doesn't allocate memory, so delete is not used.
4. Usage:
   - Standard new is used for dynamic allocation.
   - Placement new is often used in custom memory management, object pools, or when you need to construct an object at a specific memory location.
5. Syntax:
   - Standard new is followed by a type.
   - Placement new is followed by a memory address in parentheses, then a type.

## Conclusion

Placement new is advanced and should be used carefully, as it can easily lead to undefined behavior if misused. It's commonly used in scenarios where you need fine-grained control over object lifetime and memory layout.
