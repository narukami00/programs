#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int source, destination, weight;
};

class Graph {
public:
    int numVertices;
    vector<Edge> edges;

    Graph(int vertices) : numVertices(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    int findMinSpanningTree() {
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq; 
        vector<bool> visited(numVertices, false);
        int totalWeight = 0;

        // Add the first vertex to start
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            Edge currentEdge = pq.top();
            pq.pop();

            if (visited[currentEdge.destination]) continue;
            visited[currentEdge.destination] = true;
            totalWeight += currentEdge.weight;

            for (const auto& edge : edges) {
                if (!visited[edge.destination] && edge.source == currentEdge.destination) {
                    pq.push(edge);
                }
            }
        }
        return totalWeight;
    }

    void readGraph(int n, int m) {
        while(m--) {
            Edge e;
            cin >> e.source >> e.destination >> e.weight;
            addEdge(e.source, e.destination, e.weight);
            addEdge(e.destination, e.source, e.weight); // Undirected graph
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    Graph g(n);

    g.readGraph(n, m); // Read the graph from user input

    int mstWeight = g.findMinSpanningTree();
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    return 0;
}
