// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Justification for adjacency list:
// 1. Space-efficient for sparse graphs (only stores existing edges).
// 2. Faster iteration over neighbors compared to an adjacency matrix.

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjList; // Adjacency list with edge costs

    void dfs(const string& city, unordered_map<string, bool>& visited) {
        visited[city] = true;
        for (auto& neighbor : adjList[city]) {
            if (!visited[neighbor.first]) {
                dfs(neighbor.first, visited);
            }
        }
    }

public:
    // Add a flight path (edge) between two cities
    void addEdge(const string& city1, const string& city2, int cost) {
        adjList[city1].push_back({city2, cost});
        adjList[city2].push_back({city1, cost}); // Assuming undirected graph
    }

    // Check if the graph is connected
    bool isConnected() {
        if (adjList.empty()) return true;

        unordered_map<string, bool> visited;
        for (auto& city : adjList) {
            visited[city.first] = false;
        }

        // Start DFS from the first city
        auto startCity = adjList.begin()->first;
        dfs(startCity, visited);

        // Check if all cities are visited
        for (auto& city : visited) {
            if (!city.second) {
                return false;
            }
        }
        return true;
    }

    // Display the adjacency list
    void displayGraph() {
        cout << "Graph Representation (Adjacency List):" << endl;
        for (auto& city : adjList) {
            cout << city.first << " -> ";
            for (auto& neighbor : city.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph flightGraph;

    // Sample data: cities and flight paths
    flightGraph.addEdge("New York", "Los Angeles", 300);
    flightGraph.addEdge("New York", "Chicago", 200);
    flightGraph.addEdge("Chicago", "Denver", 150);
    flightGraph.addEdge("Denver", "Los Angeles", 250);
    flightGraph.addEdge("Los Angeles", "Houston", 350);

    // Display the graph
    flightGraph.displayGraph();

    // Check connectivity
    if (flightGraph.isConnected()) {
        cout << "\nThe graph is connected." << endl;
    } else {
        cout << "\nThe graph is not connected." << endl;
    }

    return 0;
}
