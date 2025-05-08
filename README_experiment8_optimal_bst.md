# Experiment 8: Optimal Binary Search Tree (OBST)

## Objective

To construct an Optimal Binary Search Tree (OBST) given a set of keys and their access probabilities, and to display the minimum search cost and the structure of the OBST.

## Concept

A **Binary Search Tree (BST)** is a binary tree in which each node contains a key, and for every node:
- All keys in the left subtree are less than the node's key.
- All keys in the right subtree are greater than the node's key.

An **Optimal BST** is a BST that minimizes the expected search cost, given the probabilities of searching for each key. The structure of the tree depends on these probabilities.

### Why OBST?

- In applications like dictionaries, databases, and compilers, some keys are accessed more frequently than others.
- Placing frequently accessed keys closer to the root reduces the average search time.

## Implementation Details

- **Input:** Number of keys and their access probabilities (p1 to pn).
- **Cost Table:** `cost[i][j]` stores the minimum cost of searching keys from i to j.
- **Root Table:** `root[i][j]` stores the root of the subtree for keys i to j.
- **Dynamic Programming:** The algorithm fills the cost and root tables for all possible subtrees.
- **Sum Array:** Used to quickly calculate the sum of probabilities in a range.
- **Output:** Minimum search cost and the structure of the OBST (which key is root, left child, right child, etc.).

## Code Flow

1. User enters the number of keys and their access probabilities.
2. The program computes the cost and root tables using dynamic programming.
3. The minimum search cost is displayed.
4. The structure of the OBST is printed recursively.

## Sample Output

```
Enter number of keys: 3
Enter access probabilities (p1 to p3): 0.3 0.2 0.5

Minimum search cost: 1.5

BST Structure:
Key 3 is the root
Key 1 is the left child of Key 3
Key 2 is the right child of Key 1
```

## Complexity Analysis

- **Time Complexity:** O(n^3), where n is the number of keys (due to three nested loops).
- **Space Complexity:** O(n^2) for the cost and root tables.

## Key Points to Explain

- **Dynamic Programming:** Used to avoid redundant calculations by storing results of subproblems.
- **Optimal Substructure:** The optimal solution for a range depends on optimal solutions of its subranges.
- **Practical Applications:** Used in compiler design, search optimization, and database indexing.

## Viva Questions

- What is an Optimal BST? Why is it needed?
- How is the minimum search cost calculated?
- What is the role of dynamic programming in OBST?
- How does the structure of the OBST depend on probabilities?
- What is the time complexity of the OBST algorithm?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

