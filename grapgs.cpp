#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight; // distance or time
};

void bfs(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal from node " << start << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (auto& edge : graph[u]) {
            int v = edge.to;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

void dijkstra(int start, int end, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    using P = pair<int,int>; // (distance, node)
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currDist > dist[u]) continue;

        if (u == end) break; // reached destination

        for (auto& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[end] == INF) {
        cout << "No path from " << start << " to " << end << "\n";
        return;
    }

    // Reconstruct path
    stack<int> path;
    for (int cur = end; cur != -1; cur = parent[cur])
        path.push(cur);

    cout << "Shortest path from " << start << " to " << end << ": ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << "\nTotal distance/time: " << dist[end] << "\n";
}

int main() {
    int intersections, roads;
    cout << "Enter number of intersections and roads: ";
    cin >> intersections >> roads;

    vector<vector<Edge>> graph(intersections);

    cout << "Enter roads in format: from to distance/time\n";
    for (int i = 0; i < roads; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Assuming undirected graph (two-way roads)
    }

    int source, destination;
    cout << "Enter source and destination intersections: ";
    cin >> source >> destination;

    cout << "\n";
    bfs(source, graph);
    cout << "\n";
    dijkstra(source, destination, graph);

    return 0;
}




