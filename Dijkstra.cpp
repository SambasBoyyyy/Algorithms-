#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

#define INF numeric_limits<int>::max()

// Structure to represent an edge
struct Edge {
    int to;
    int weight;
};

// Dijkstra's Algorithm function
void dijkstra(vector<vector<Edge>>& graph, int source) {
    int n = graph.size(); // Number of nodes in the graph
    vector<int> dist(n, INF); // Initialize distances to all nodes as infinity
    vector<int> prev(n, -1); // Initialize predecessors to -1 (undefined)
    dist[source] = 0; // Distance from source to itself is 0

    // Priority queue to store nodes to visit
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // Push the source node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        // Visit neighbors of the current node
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                prev[v] = u; // Update predecessor of v to u
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest path from source to node 4
    int targetNode = 4;
    cout << "Shortest path from node " << source << " to node " << targetNode << ":\n";
    if (dist[targetNode] == INF) {
        cout << "No path exists!\n";
        return;
    }

    vector<int> path;
    for (int v = targetNode; v != -1; v = prev[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    int numNodes = 5; // Number of nodes in the graph
    vector<vector<Edge>> graph(numNodes);

    // Adding edges to the graph
    // (Your edge additions remain the same)
graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});

    graph[1].push_back({3, 2});
    graph[1].push_back({4, 3});
    graph[1].push_back({2, 3});

    graph[2].push_back({1, 1});
    graph[2].push_back({4, 5});

    graph[4].push_back({3, 1}); 
    int sourceNode = 0; // Source node for Dijkstra's algorithm

    // Run Dijkstra's algorithm
    dijkstra(graph, sourceNode);

    return 0;
}


  