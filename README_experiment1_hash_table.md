# Experiment 1: Hash Table Implementation (Linear Probing & Chaining)

## Objective

To implement and compare two collision resolution techniques in hash tables:
- **Linear Probing (Open Addressing)**
- **Chaining (Closed Addressing)**

## Concept

A **hash table** is a data structure that maps keys to values using a hash function. The hash function computes an index into an array of buckets or slots, from which the desired value can be found.

### Why Hash Tables?

- Fast data retrieval (average-case O(1) time complexity for search, insert, and delete)
- Used in applications like databases, caches, and sets/maps in programming languages

### Hash Function

A hash function converts a key (like a name) into an integer index within the table's size. In Python, `hash(key) % size` is commonly used.

## Collision Resolution Techniques

### 1. Linear Probing (Open Addressing)

- If a collision occurs (i.e., the slot is already occupied), the algorithm checks the next slot (index + 1), wrapping around to the start if needed.
- This continues until an empty slot is found.
- **Pros:** Simple, no extra memory for pointers.
- **Cons:** Clustering can occur, degrading performance.

### 2. Chaining (Closed Addressing)

- Each slot in the hash table contains a list (chain) of all elements that hash to the same index.
- On collision, the new element is simply added to the list at that index.
- **Pros:** Simple to implement, less sensitive to load factor.
- **Cons:** Requires extra memory for pointers/lists.

## Implementation Details

- Both techniques are implemented as Python classes: `HashTableLinearProbing` and `HashTableChaining`.
- Each class supports `insert` and `search` operations.
- The program allows the user to input the size of the hash table and records (name and phone number).
- It measures and prints the number of comparisons made during search operations for both techniques.

## Performance Comparison

- **Linear Probing:** Comparisons may increase as the table fills up due to clustering.
- **Chaining:** Comparisons depend on the length of the chain at each index.

## Sample Usage

1. User enters the size of the hash table and number of records.
2. User inputs name and phone number pairs.
3. The program inserts all records using both techniques.
4. For each record, it searches and prints the number of comparisons required.
5. Finally, it prints the total number of comparisons for both methods.

## Key Points to Explain

- **Hash Table Structure:** Array-based, with indices determined by hash function.
- **Collision Handling:** Linear probing searches for next available slot; chaining uses linked lists.
- **Efficiency:** Both methods aim for O(1) average-case performance, but degrade differently under high load.
- **Practical Applications:** Used in dictionaries, symbol tables, caches, etc.

## Example Questions for Viva

- What is a hash function? Why is it important?
- How does linear probing handle collisions?
- What are the drawbacks of linear probing?
- How does chaining differ from open addressing?
- When would you prefer chaining over linear probing?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

