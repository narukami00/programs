#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Structure to store distance and parent for each node
struct Node {
    int dist;
    int parent;
    Node(int d, int p) : dist(d), parent(p) {}
};

// Function to find shortest path using Bellman-Ford algorithm
vector<int> bellmanFord(int n, vector<vector<pair<int, int>>> &graph, int source) {
    // Initialize distances with infinity
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto &edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    
    // Check for negative cycles
    for (int u = 0; u < n; u++) {
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                // Negative cycle detected
                cout << "Negative cycle detected. No shortest path exists." << endl;
                return vector<int>();
            }
        }
    }
    
    return dist;
}

// Function to reconstruct the path
vector<int> reconstructPath(int n, vector<vector<pair<int, int>>> &graph, int source, vector<int> &dist) {
    vector<int> path;
    int dest = n - 1; // Assuming destination is the last node (n-1)
    
    // Check if destination is reachable
    if (dist[dest] == INT_MAX) {
        cout << "No path exists from source to destination." << endl;
        return vector<int>();
    }
    
    // Reconstruct path using parent information
    int current = dest;
    while (current != source) {
        path.push_back(current);
        bool found = false;
        for (int u = 0; u < n; u++) {
            for (auto &edge : graph[u]) {
                if (edge.first == current && dist[u] + edge.second == dist[current]) {
                    current = u;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) break;
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    
    vector<vector<pair<int, int>>> graph(n);
    
    cout << "Enter edges (u v w) where u is source, v is destination, and w is weight:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    int source;
    cout << "Enter source node: ";
    cin >> source;
    
    vector<int> dist = bellmanFord(n, graph, source);
    
    if (dist.empty()) {
        return 0;
    }
    
    int dest = n - 1; // Assuming destination is the last node (n-1)
    if (dist[dest] == INT_MAX) {
        cout << "No path exists from source to destination." << endl;
        return 0;
    }
    
    vector<int> path = reconstructPath(n, graph, source, dist);
    
    cout << "Shortest distance: " << dist[dest] << endl;
    cout << "Path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}