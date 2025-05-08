# Experiment 9: Dictionary using AVL Tree

## Objective

To implement a dictionary using an AVL tree, supporting insertion, deletion, update, and display operations, and to demonstrate the self-balancing property of AVL trees.

## Concept

An **AVL tree** is a self-balancing binary search tree (BST) where the difference in heights of left and right subtrees (the balance factor) for every node is at most 1. This ensures that the tree remains balanced, providing O(log n) time complexity for insertion, deletion, and search operations.

### Why AVL Tree for Dictionary?

- Ensures fast lookup, insertion, and deletion.
- Maintains sorted order of keys, allowing easy display in ascending order.
- Automatically balances itself after every operation.

## Implementation Details

- **Node Structure:** Each node contains a keyword, its meaning, left and right child pointers, and its height.
- **Insertion:** Adds a new keyword-meaning pair. If the keyword exists, its meaning is updated. After insertion, the tree is balanced using rotations if necessary.
- **Deletion:** Removes a keyword from the dictionary and re-balances the tree.
- **Update:** Updates the meaning of an existing keyword (implemented as an insert operation).
- **Display:** Inorder traversal is used to display the dictionary in ascending order of keywords.
- **Max Comparisons:** The height of the tree gives the maximum number of comparisons needed for a search.

## Code Flow

1. Insert several keyword-meaning pairs into the AVL tree.
2. Display the dictionary in ascending order.
3. Update the meaning of a keyword and display the dictionary again.
4. Delete a keyword and display the dictionary.
5. Display the maximum number of comparisons required for searching (tree height).

## Sample Output

```
Glossary in Ascending Order:
Algorithm: A step-by-step procedure for solving a problem.
BinaryTree: A tree data structure with at most two children.
Queue: A linear structure which follows FIFO order.

Updating 'Queue' meaning...
Algorithm: A step-by-step procedure for solving a problem.
BinaryTree: A tree data structure with at most two children.
Queue: A collection where elements are added at one end and removed from the other.

Deleting 'BinaryTree'...
Algorithm: A step-by-step procedure for solving a problem.
Queue: A collection where elements are added at one end and removed from the other.

Max Comparisons for Searching: 2
```

## Complexity Analysis

- **Insertion/Deletion/Search:** O(log n) due to self-balancing property.
- **Display (Inorder Traversal):** O(n).

## Key Points to Explain

- **AVL Tree Properties:** Balance factor, rotations (left, right, left-right, right-left).
- **Why AVL over simple BST:** Guarantees balanced tree and efficient operations.
- **Dictionary Operations:** Insert, delete, update, display.
- **Applications:** Used in databases, memory management, and any application requiring fast, ordered data retrieval.

## Viva Questions

- What is an AVL tree? How does it maintain balance?
- What are the types of rotations in AVL trees?
- How does AVL tree improve over a regular BST?
- How is the maximum number of comparisons for searching determined?
- What is the time complexity of AVL tree operations?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

