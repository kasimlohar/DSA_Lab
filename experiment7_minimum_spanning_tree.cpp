// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

class Edge {
public:
    int src, dest, weight;
};

int parent[MAX];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    Edge edges[MAX];
    int V, E;
    cout << "Enter number of offices (nodes): ";
    cin >> V;
    cout << "Enter number of connections (edges): ";
    cin >> E;

    cout << "Enter source, destination, and cost of each connection:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Simple bubble sort for edges by weight
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < V; i++) parent[i] = i;

    int totalCost = 0;
    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            unite(u, v);
            cout << u << " - " << v << " : " << w << "\n";
            totalCost += w;
        }
    }

    cout << "Total Minimum Cost: " << totalCost << endl;
    return 0;
}
