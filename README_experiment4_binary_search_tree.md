# Experiment 4: Binary Search Tree (BST) Operations

## Objective

To implement a Binary Search Tree (BST) and perform the following operations:
- Insertion of elements
- Inorder traversal
- Finding the height of the tree
- Finding the minimum value
- Searching for a value
- Mirroring the tree

## Concept

A **Binary Search Tree (BST)** is a binary tree in which each node has at most two children, and for every node:
- All values in the left subtree are less than the node's value.
- All values in the right subtree are greater than the node's value.

BSTs allow efficient searching, insertion, and deletion of elements.

## Implementation Details

- **TreeNode Class:** Represents each node with an integer value and pointers to left and right children.
- **BST Class:** Contains the root node and methods for all BST operations.
  - **Insertion:** Recursively inserts a value in the correct position to maintain BST property.
  - **Inorder Traversal:** Prints the tree in sorted order (left, root, right).
  - **Find Height:** Returns the height (maximum depth) of the tree.
  - **Find Minimum:** Returns the smallest value in the tree (leftmost node).
  - **Search:** Checks if a value exists in the tree.
  - **Mirror:** Recursively swaps left and right children of all nodes, producing the mirror image of the tree.

## Code Flow

1. User enters the number of elements and the elements to insert.
2. The BST is constructed by inserting each element.
3. The program displays:
   - Inorder traversal (sorted order)
   - Height of the BST
   - Minimum value in the BST
4. User can search for a value.
5. The tree is mirrored, and the inorder traversal of the mirrored tree is displayed.

## Sample Output

```
Enter the number of elements to insert into the BST: 5
Enter the elements: 10 5 20 3 7

Inorder traversal of the BST: 3 5 7 10 20 
Height of the BST: 3
Minimum value in the BST: 3
Enter a value to search in the BST: 7
7 is found in the BST.

Mirroring the BST...
Inorder traversal after mirroring: 20 10 7 5 3 
```

## Complexity Analysis

- **Insertion/Search:** O(h), where h is the height of the tree (O(log n) for balanced BST, O(n) for skewed).
- **Inorder Traversal:** O(n), visits every node once.
- **Find Height:** O(n), visits every node.
- **Find Minimum:** O(h), follows the leftmost path.
- **Mirror:** O(n), visits every node once.

## Key Points to Explain

- **BST Properties:** Left < Root < Right.
- **Recursive Implementation:** Most operations are implemented recursively.
- **Inorder Traversal:** Produces sorted order for BST.
- **Mirroring:** Swaps left and right children at every node.
- **Applications:** Used in searching, sorting, and as the basis for more advanced trees (AVL, Red-Black).

## Viva Questions

- What is a BST? How does it differ from a binary tree?
- What is the time complexity of insertion and search in a BST?
- How do you find the minimum value in a BST?
- What is the effect of mirroring a BST?
- What happens if you insert elements in sorted order?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

