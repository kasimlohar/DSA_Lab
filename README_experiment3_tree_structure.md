# Experiment 3: Tree Structure Representation of a Book

## Objective

To implement a tree data structure to represent the hierarchical structure of a book (Book → Chapters → Sections) and perform level order traversal to display the structure.

## Concept

A **tree** is a non-linear data structure consisting of nodes connected by edges. Each node contains data and references to its child nodes. The topmost node is called the root. Trees are used to represent hierarchical relationships, such as file systems, organizational structures, and in this experiment, the structure of a book.

### Book as a Tree

- **Root Node:** Represents the book title.
- **First Level Children:** Represent chapters of the book.
- **Second Level Children:** Represent sections within each chapter.

This hierarchical representation makes it easy to visualize and manage the contents of a book.

## Implementation Details

- **Node Class:** Each node contains a string (`data`) and a list of pointers to its children.
- **Dynamic Tree Construction:** The user is prompted to enter the book title, number of chapters, chapter names, number of sections per chapter, and section names. The tree is built dynamically based on user input.
- **Level Order Traversal:** The tree is displayed using level order traversal (breadth-first), printing all nodes at each level before moving to the next.

### Memory Management

- The destructor (`~Node`) recursively deletes all child nodes to prevent memory leaks.

## Code Flow

1. **Input:**
   - User enters the book title.
   - User enters the number of chapters and their names.
   - For each chapter, user enters the number of sections and their names.
2. **Tree Construction:**
   - The tree is built as per the input, with appropriate parent-child relationships.
3. **Display:**
   - The tree is displayed using level order traversal, showing the book, chapters, and sections in a structured manner.

## Sample Output

```
Enter book title: DataStructures
Enter number of chapters: 2
Enter chapter 1: Introduction
Enter number of sections in Introduction: 2
Enter section 1 in Introduction: Basics
Enter section 2 in Introduction: Applications
Enter chapter 2: Trees
Enter number of sections in Trees: 1
Enter section 1 in Trees: Binary Trees

Tree Structure (Level Order Traversal):
DataStructures 
Introduction Trees 
Basics Applications Binary Trees 
```

## Complexity Analysis

- **Time Complexity:**
  - Tree construction: O(n), where n is the total number of nodes (book + chapters + sections).
  - Level order traversal: O(n), as each node is visited once.
- **Space Complexity:**
  - O(n) for storing all nodes.
  - O(w) auxiliary space for traversal, where w is the maximum width of the tree (max nodes at any level).

## Key Points to Explain

- **Tree Structure:** Hierarchical, non-linear, suitable for representing nested relationships.
- **Level Order Traversal:** Uses a queue to visit nodes level by level.
- **Dynamic Construction:** Tree is built based on user input, not hardcoded.
- **Memory Management:** Destructor ensures all dynamically allocated nodes are deleted.

## Viva Questions

- What is a tree? How is it different from a linear data structure?
- How does level order traversal work?
- Why use a tree to represent a book structure?
- How is memory managed in this implementation?
- What are real-life applications of trees?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

