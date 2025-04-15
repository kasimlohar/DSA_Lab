// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges;

    // Find the root of a node in the disjoint set
    int find(vector<int>& parent, int node) {
        if (parent[node] != node) {
            parent[node] = find(parent, parent[node]); // Path compression
        }
        return parent[node];
    }

    // Union of two subsets
    void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }

    void kruskalMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initialize disjoint sets
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        vector<Edge> mst;
        int totalCost = 0;

        for (Edge& edge : edges) {
            int rootU = find(parent, edge.src);
            int rootV = find(parent, edge.dest);

            if (rootU != rootV) {
                mst.push_back(edge);
                totalCost += edge.weight;
                unionSets(parent, rank, rootU, rootV);
            }
        }

        // Print the MST
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (Edge& edge : mst) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
        cout << "Total cost of MST: " << totalCost << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of offices (nodes): ";
    cin >> V;

    Graph graph(V);

    cout << "Enter the number of potential phone lines (edges): ";
    cin >> E;

    cout << "Enter the edges (source, destination, cost):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    cout << "\nFinding the Minimum Spanning Tree using Kruskal's Algorithm..." << endl;
    graph.kruskalMST();

    return 0;
}
