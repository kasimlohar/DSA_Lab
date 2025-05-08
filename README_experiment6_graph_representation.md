# Experiment 6: Graph Representation using Adjacency List

## Objective

To represent a network of cities connected by flight paths using a graph, implement the adjacency list representation, and check if the graph is connected.

## Concept

A **graph** is a collection of nodes (vertices) and edges connecting pairs of nodes. In this experiment:
- **Vertices:** Represent cities.
- **Edges:** Represent direct flight paths between cities, with associated costs.

### Adjacency List

- An adjacency list is a space-efficient way to represent a graph, especially when the graph is sparse (few edges compared to the number of vertices).
- Each vertex (city) has a list of its neighbors (other cities directly connected by a flight), along with the cost of the flight.

#### Why Adjacency List?
- Saves space for sparse graphs (compared to adjacency matrix).
- Faster iteration over neighbors.

## Implementation Details

- **Graph Class:** Uses an unordered map to store the adjacency list, where each city maps to a vector of pairs (neighbor city, cost).
- **addEdge:** Adds a bidirectional (undirected) edge between two cities with a given cost.
- **displayGraph:** Prints the adjacency list for all cities.
- **isConnected:** Uses Depth-First Search (DFS) to check if all cities are reachable from any starting city.

## Code Flow

1. The program creates a graph and adds sample cities and flight paths.
2. The adjacency list is displayed.
3. The program checks if the graph is connected (i.e., every city can be reached from any other city).

## Sample Output

```
Graph Representation (Adjacency List):
New York -> (Los Angeles, 300) (Chicago, 200) 
Los Angeles -> (New York, 300) (Denver, 250) (Houston, 350) 
Chicago -> (New York, 200) (Denver, 150) 
Denver -> (Chicago, 150) (Los Angeles, 250) 
Houston -> (Los Angeles, 350) 

The graph is connected.
```

## Complexity Analysis

- **Space Complexity:** O(V + E), where V is the number of cities and E is the number of flight paths.
- **DFS Traversal:** O(V + E), visits each city and edge once.

## Key Points to Explain

- **Adjacency List vs. Adjacency Matrix:** List is more space-efficient for sparse graphs.
- **DFS for Connectivity:** DFS marks all reachable cities; if any city is unvisited after DFS, the graph is not connected.
- **Applications:** Used in airline route maps, social networks, road networks, etc.

## Viva Questions

- What is an adjacency list? When is it preferred over an adjacency matrix?
- How do you check if a graph is connected?
- What is the time complexity of DFS?
- How would you modify the code for a directed graph?
- What are real-world applications of graph representations?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

