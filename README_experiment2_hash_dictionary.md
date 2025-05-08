# Experiment 2: Hash Dictionary using Hash Table with Chaining

## Objective

To implement a dictionary (key-value store) using a hash table with chaining for collision resolution, and to provide operations for insertion, search, deletion, and display.

## Concept

A **dictionary** is a data structure that stores data in key-value pairs, allowing efficient insertion, lookup, and deletion by key. In Python, the built-in `dict` type is an example.

A **hash table** is used to implement the dictionary. It uses a hash function to map keys to indices in an array (the table). If two keys hash to the same index (collision), chaining is used: each table slot contains a list of all key-value pairs that hash to that index.

### Hash Function

- The hash function computes an integer index from the key: `hash(key) % size`.
- This ensures keys are distributed across the table.

### Chaining

- Each slot in the table is a list (bucket).
- On collision, new key-value pairs are appended to the list at that index.

## Implementation Details

- The `HashDictionary` class implements the dictionary using a hash table with chaining.
- **Methods:**
  - `insert(key, value)`: Adds a key-value pair. Raises an error if the key already exists.
  - `find(key)`: Returns the value for a given key. Raises an error if the key is not found.
  - `delete(key)`: Removes the key-value pair for the given key. Raises an error if the key is not found.
  - `display()`: Prints the contents of the hash table (all buckets).
- The main function provides a menu-driven interface for the user to interact with the dictionary.

## Usage

1. User specifies the size of the hash table.
2. User can insert, find, delete, or display key-value pairs using menu options.
3. Duplicate keys are not allowed.
4. All operations handle errors gracefully and provide feedback.

## Key Points to Explain

- **Hash Table Structure:** Array of buckets (lists), with indices determined by the hash function.
- **Collision Handling:** Chaining allows multiple key-value pairs at the same index.
- **Efficiency:** Average-case O(1) time for insert, find, and delete if the hash function distributes keys well.
- **Practical Applications:** Used in symbol tables, caches, and as the basis for Python's `dict`.

## Example Questions for Viva

- What is a hash table? How does it work?
- How does chaining resolve collisions?
- What happens if you try to insert a duplicate key?
- How is deletion handled in this implementation?
- What are the advantages and disadvantages of chaining?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

