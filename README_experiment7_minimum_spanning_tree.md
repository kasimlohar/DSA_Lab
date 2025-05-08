# Experiment 7: Minimum Spanning Tree using Kruskal's Algorithm

## Objective

To find the Minimum Spanning Tree (MST) of a network of offices (nodes) connected by phone lines (edges) using Kruskal's algorithm.

## Concept

A **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph is a subset of the edges that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.

**Kruskal's Algorithm** is a greedy algorithm that finds an MST by:
1. Sorting all the edges in non-decreasing order of their weights.
2. Adding edges one by one to the MST, picking the smallest edge that does not form a cycle.
3. Using a disjoint-set (union-find) data structure to detect cycles efficiently.

## Implementation Details

- **Edge Class:** Represents an edge with source, destination, and weight.
- **Disjoint Set (Union-Find):** Used to check if adding an edge forms a cycle.
- **Input:** User enters the number of offices (nodes), number of connections (edges), and the details of each connection (source, destination, cost).
- **Sorting:** Edges are sorted by weight using bubble sort for simplicity.
- **MST Construction:** Edges are added to the MST if they connect different components (no cycle).
- **Output:** The edges in the MST and the total minimum cost.

## Code Flow

1. User inputs the number of offices and connections.
2. User enters each connection (source, destination, cost).
3. Edges are sorted by cost.
4. The algorithm iterates through the sorted edges, adding them to the MST if they do not form a cycle.
5. The MST edges and total cost are displayed.

## Sample Output

```
Enter number of offices (nodes): 4
Enter number of connections (edges): 5
Enter source, destination, and cost of each connection:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Minimum Spanning Tree:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
Total Minimum Cost: 19
```

## Complexity Analysis

- **Sorting Edges:** O(E^2) with bubble sort (for small E), O(E log E) with efficient sort.
- **Union-Find Operations:** Nearly O(1) per operation with path compression.
- **Overall:** O(E log E) with efficient sorting.

## Key Points to Explain

- **MST Definition:** Connects all nodes with minimum total cost, no cycles.
- **Kruskal's Algorithm:** Greedy, edge-based, uses sorting and union-find.
- **Cycle Detection:** Union-find structure ensures no cycles are formed.
- **Applications:** Network design (telecom, computer, road networks).

## Viva Questions

- What is a Minimum Spanning Tree?
- How does Kruskal's algorithm work?
- How do you detect cycles in Kruskal's algorithm?
- What is the time complexity of Kruskal's algorithm?
- Where are MSTs used in real life?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

