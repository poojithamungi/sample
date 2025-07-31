/**
 * @brief Includes the input/output stream library for console input and output operations.
 * 
 * This header provides standard input and output stream functionality,
 * including std::cout for printing to the console and std::cin for reading input.
 */
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) 
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) 
    {
        if (!visited[neighbor])
            DFS(neighbor, adj, visited);
    }
}

int main() 
{
    int n = 5; // number of nodes
    vector<vector<int>> adj(n);
    // Example edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};
    vector<bool> visited(n, false);
    DFS(0, adj, visited);
    return 0;
}
