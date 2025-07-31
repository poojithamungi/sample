#include <iostream>
#include <vector>
#include <queue>
#include <utility>
 
using namespace std;
 
const int INF = 1e9;
 
void primMST(int V, vector<pair<int, int>> adj[]) {
    // Min-heap priority queue to select edge with minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
    vector<int> key(V, INF);       // Key values to pick minimum weight edge
    vector<int> parent(V, -1);     // Store MST
    vector<bool> inMST(V, false);  // To keep track of vertices in MST
 
    key[0] = 0;       // Start from vertex 0
    pq.push({0, 0});  // (key, vertex)
 
        while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
 
        inMST[u] = true;
 
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
 
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
 
 
    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
}
 
int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> adj[V];
 
    // Add edges (u, v, w)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
 
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
 
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
 
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
 
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
 
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});
 
    primMST(V, adj);
 
    return 0;
}