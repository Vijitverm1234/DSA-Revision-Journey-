#include <vector>
#include <queue>
#include <climits>

std::vector<int> dijkstra(int n, int m, std::vector<std::vector<int>>& edges) {
    // Create adjacency list
    std::vector<std::pair<int, int>> adj[n];
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v, w});
    }

    // Initialize distances and priority queue
    std::vector<int> dis(n, INT_MAX);
    dis[0] = 0; // Source node
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, 0}); // {distance, node}

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip if we've found a longer path
        if (dist > dis[node]) continue;

        // Relax edges
        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;
            if (dis[node] + w < dis[v]) {
                dis[v] = dis[node] + w;
                pq.push({dis[v], v});
            }
        }
    }

    // Mark unreachable nodes as -1
    for (int i = 0; i < n; i++) {
        if (dis[i] == INT_MAX) dis[i] = -1;
    }
    return dis;
}