# Data Structures

- [Data Structures](#data-structures)
  - [TL;DR](#tldr)
  - [List Interface](#list-interface)
  - [Set Interface](#set-interface)
  - [Map Interface](#map-interface)
  - [Queue Interface](#queue-interface)
  - [Deque Interface](#deque-interface)
  - [Stack Interface](#stack-interface)
  - [Examples](#examples)

## TL;DR

| Interface | Classes       | Use Cases                               | Advantages                                                                   | Disadvantages                                           |
| --------- | ------------- | --------------------------------------- | ---------------------------------------------------------------------------- | ------------------------------------------------------- |
| List      | ArrayList     | Ordered collection, random access       | Fast random access (O(1)), dynamic resizing                                  | Slow middle insertion/deletion, resizing overhead       |
|           | LinkedList    | Ordered collection, frequent insertions | Fast insertion/deletion at beginning/middle (O(1))                           | Slow random access, higher memory overhead              |
|           | Vector        | Thread-safe list, dynamic resizing      | Synchronized, fast random access (O(1))                                      | Slower due to synchronization, resizing overhead        |
| Set       | HashSet       | Unique elements, fast membership checks | Fast lookups (O(1)), insertion, and deletion                                 | No ordering, requires good hash function                |
|           | LinkedHashSet | Unique elements with insertion order    | Maintains insertion order, predictable iteration                             | Higher memory overhead                                  |
|           | TreeSet       | Unique elements in sorted order         | Sorted order, efficient for range-based operations                           | Slower operations (O(log n)), higher memory overhead    |
| Map       | HashMap       | Key-value pairs, fast lookups           | Fast lookups (O(1)), insertions, and deletions                               | No ordering, not thread-safe                            |
|           | LinkedHashMap | Key-value pairs with insertion order    | Maintains insertion order, predictable iteration                             | Higher memory overhead                                  |
|           | TreeMap       | Sorted key-value pairs                  | Maintains sorted order, useful for range queries                             | Slower operations (O(log n)), higher memory overhead    |
|           | Hashtable     | Thread-safe key-value pairs             | Synchronized, fast lookups (O(1))                                            | Slower due to synchronization, no null keys or values   |
| Queue     | LinkedList    | FIFO operations, task scheduling        | Efficient insertion/removal at both ends                                     | Higher memory overhead, slower random access            |
|           | PriorityQueue | Priority-based task scheduling          | Efficient retrieval of the smallest/largest element (O(log n))               | No predictable order except the head                    |
|           | ArrayDeque    | Fast FIFO/LIFO operations               | Fast insertion/removal at both ends (O(1)), more memory-efficient            | No random access, not thread-safe                       |
| Deque     | ArrayDeque    | Double-ended queue operations           | Fast insertion/removal at both ends (O(1)), more memory-efficient            | Not thread-safe, no random access                       |
|           | LinkedList    | Double-ended queue operations           | Efficient insertion/removal at both ends, also works as Queue/List           | Higher memory overhead, slower random access            |
| Stack     | Stack         | LIFO operations, backtracking           | Simple to use for stack operations                                           | Synchronized, slower than ArrayDeque, considered legacy |
|           | ArrayDeque    | Efficient LIFO operations               | Fast push/pop operations (O(1)), more efficient than Stack, not synchronized | Limited to stack/queue operations                       |

## List Interface

- Classes: ArrayList, LinkedList, Vector
- Use Cases: Ordered collection (can contain duplicates), random access to elements, frequently used when the number of elements is unknown or can change.
- Advantages & Disadvantages:
  - ArrayList:
    - Advantages: Fast random access (O(1)), dynamic resizing, efficient for read-heavy operations.
    - Disadvantages: Slower insertion/deletion in the middle (O(n)), resizing overhead when adding many elements.
  - LinkedList:
    - Advantages: Efficient insertion/deletion at the beginning or middle (O(1) for add/remove), no resizing overhead.
    - Disadvantages: Slower random access (O(n)), higher memory overhead due to storing node pointers.
  - Vector:
    - Advantages: Synchronized, dynamic resizing like ArrayList.
    - Disadvantages: Generally slower due to synchronization, resizing overhead.

## Set Interface

- Classes: HashSet, LinkedHashSet, TreeSet
- Use Cases: Unique elements, fast membership checks, avoiding duplicates.
- Advantages & Disadvantages:
  - HashSet:
    - Advantages: Fast membership checks (O(1)), insertion, and deletion.
    - Disadvantages: No ordering of elements, requires good hash function.
  - LinkedHashSet:
    - Advantages: Maintains insertion order, fast access (O(1)).
    - Disadvantages: Slightly more memory overhead than HashSet due to maintaining order.
  - TreeSet:
    - Advantages: Maintains elements in sorted order, useful for range-based operations.
    - Disadvantages: Slower operations (O(log n)), higher memory overhead.

## Map Interface

- Classes: HashMap, LinkedHashMap, TreeMap, Hashtable
- Use Cases: Key-value pairs, fast lookups, and retrieval by key.
- Advantages & Disadvantages:
  - HashMap:
    - Advantages: Fast lookups, insertions, and deletions (O(1)).
    - Disadvantages: No ordering of elements, not thread-safe.
  - LinkedHashMap:
    - Advantages: Maintains insertion order, predictable iteration order, fast operations (O(1)).
    - Disadvantages: Higher memory overhead due to maintaining order.
  - TreeMap:
    - Advantages: Maintains elements in sorted order, useful for range queries and ordered maps.
    - Disadvantages: Slower operations (O(log n)), higher memory overhead.
  - Hashtable:
    - Advantages: Synchronized, fast lookups (O(1)).
    - Disadvantages: Generally slower due to synchronization, does not allow null keys or values.

## Queue Interface

- Classes: LinkedList, PriorityQueue, ArrayDeque
- Use Cases: FIFO (First-In-First-Out) operations, task scheduling, and managing a sequence of elements.
- Advantages & Disadvantages:
  - LinkedList (as Queue):
    - Advantages: Efficient insertion/removal at both ends, supports both Queue and Deque interfaces.
    - Disadvantages: Higher memory overhead, slower random access.
  - PriorityQueue:
    - Advantages: Efficiently retrieves the smallest/largest element (O(log n)), useful for priority-based task scheduling.
    - Disadvantages: No predictable order for elements other than the head, not ideal for random access.
  - ArrayDeque:
    - Advantages: Fast insertion/removal at both ends (O(1)), more memory-efficient than LinkedList.
    - Disadvantages: No random access, limited to being used as a Queue/Deque.

## Deque Interface

- Classes: ArrayDeque, LinkedList
- Use Cases: Double-ended queue operations, where elements can be added or removed from both ends.
- Advantages & Disadvantages:
  - ArrayDeque:
    - Advantages: Fast insertion/removal at both ends (O(1)), more memory-efficient.
    - Disadvantages: Not thread-safe, no random access.
  - LinkedList (as Deque):
    - Advantages: Efficient insertion/removal at both ends, also works as a Queue/List.
    - Disadvantages: Higher memory overhead, slower random access.

## Stack Interface

- Classes: Stack, ArrayDeque (recommended over Stack)
- Use Cases: LIFO (Last-In-First-Out) operations, used in algorithms like DFS, backtracking.
- Advantages & Disadvantages:
  - Stack:
    - Advantages: Simple to use for stack operations.
    - Disadvantages: Synchronized, generally slower than ArrayDeque, considered legacy.
  - ArrayDeque (as Stack):
    - Advantages: Fast push/pop operations (O(1)), not synchronized, more efficient than Stack.
    - Disadvantages: Limited to stack/queue operations.

## Examples

```java
// List Interface
List<Integer> arrayList = new ArrayList<>();
List<Integer> linkedList = new LinkedList<>();
List<Integer> vector = new Vector<>();

// Set Interface
Set<Integer> hashSet = new HashSet<>();
Set<Integer> linkedHashSet = new LinkedHashSet<>();
Set<Integer> treeSet = new TreeSet<>();

// Map Interface
Map<Integer, String> hashMap = new HashMap<>();
Map<Integer, String> linkedHashMap = new LinkedHashMap<>();
Map<Integer, String> treeMap = new TreeMap<>();
Map<Integer, String> hashtable = new Hashtable<>();

// Queue Interface
Queue<Integer> linkedListQueue = new LinkedList<>();
Queue<Integer> priorityQueue = new PriorityQueue<>();
Queue<Integer> arrayDequeQueue = new ArrayDeque<>();

// Deque Interface
Deque<Integer> arrayDeque = new ArrayDeque<>();
Deque<Integer> linkedListDeque = new LinkedList<>();

// Stack Interface
Stack<Integer> stack = new Stack<>();
Deque<Integer> stackDeque = new ArrayDeque<>();  // Recommended over Stack
```
