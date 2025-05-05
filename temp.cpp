#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    int numEdges = 10; // Number of edges
    int numVertices = 5; // Number of vertices
    vector<vector<int>> edges;

    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % numVertices; // Random vertex u
        int v = rand() % numVertices; // Random vertex v
        while (v == u) {
            v = rand() % numVertices; // Ensure v is different from u
        }
        int weight = rand() % 100 + 1; // Random weight between 1 and 100
        edges.push_back({u, v, weight});
    }

    for (const auto &edge : edges) {
        cout << "Edge: " << edge[0] << " -> " << edge[1] << " with weight " << edge[2] << endl;
    }

    return 0;
}

