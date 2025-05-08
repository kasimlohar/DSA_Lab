# Experiment 5: Expression Tree Construction and Non-Recursive Postorder Traversal

## Objective

To construct an expression tree from a prefix expression, perform a non-recursive postorder traversal, and demonstrate tree deletion.

## Concept

An **expression tree** is a binary tree used to represent arithmetic expressions. Internal nodes are operators, and leaf nodes are operands. Expression trees are useful for evaluating, converting, and visualizing expressions.

- **Prefix Expression:** Operators precede their operands (e.g., `+AB`).
- **Postorder Traversal:** Visits left subtree, right subtree, then the node itself. For expression trees, postorder traversal yields the postfix (Reverse Polish) notation.

## Implementation Details

- **Node Class:** Represents each node with a character (`data`) and pointers to left and right children.
- **ExpressionTree Class:**
  - **buildTreeFromPrefix:** Constructs the tree from a prefix expression using a stack. Scans the prefix string from right to left, creating nodes for operands and operators, and linking them appropriately.
  - **postorderTraversal:** Uses two stacks to perform a non-recursive postorder traversal and prints the result.
  - **deleteTree:** Recursively deletes all nodes to free memory.
- **isOperator:** Helper function to check if a character is an operator.

## Code Flow

1. User enters a prefix expression (e.g., `*+AB-CD`).
2. The tree is constructed from the prefix expression.
3. The program performs and prints a non-recursive postorder traversal (postfix form).
4. The tree is deleted, and the program confirms deletion.

## Sample Output

```
Enter a prefix expression: *+AB-CD

Performing postorder traversal...
Postorder Traversal: A B + C D - *

Deleting the tree...
Tree deleted successfully.
```

## Complexity Analysis

- **Tree Construction:** O(n), where n is the length of the prefix expression.
- **Postorder Traversal:** O(n), each node is visited once.
- **Tree Deletion:** O(n), each node is deleted once.

## Key Points to Explain

- **Expression Tree Structure:** Operators as internal nodes, operands as leaves.
- **Prefix to Tree Construction:** Right-to-left scan, stack-based approach.
- **Non-Recursive Traversal:** Uses two stacks to avoid recursion.
- **Memory Management:** Explicit deletion of all nodes.
- **Applications:** Expression evaluation, conversion between infix/prefix/postfix, compiler design.

## Viva Questions

- What is an expression tree? Where is it used?
- How do you construct an expression tree from a prefix expression?
- What is the difference between recursive and non-recursive traversal?
- What does postorder traversal of an expression tree represent?
- How is memory managed in this implementation?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

