#include <bits/stdc++.h>
using namespace std;
int timer = 1;
void dfs(int node, int parent, vector<int>& low, vector<int>& tin, vector<vector<int>>& adj, vector<bool>& vis, vector<vector<int>>& bridges) {
    vis[node] = true;
    low[node] = tin[node] = timer;
    timer++;
    for(auto it: adj[node]) {
        if(it == parent)
            continue;
        if(!vis[it]) {
            dfs(it, node, low, tin, adj, vis, bridges);
            low[node] = min(low[node], low[it]);
            // checking is that bridge or not?
            if(tin[node] < low[it])
                bridges.push_back({node, it});
            }
        else {
            // if it is already visited it can't be the bridge
            low[node] = min(low[node], low[it]);
        }
    }
}
// Tarjan's algorithm
// Used to find bridges in graph
// Time complexity: O(V+2E) (same as DFS)
// Space complexity: O(V+2E)+O(3V)
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    for(auto it: connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<vector<int>> bridges;
    vector<int> tin(n); // time of insertion of node
    vector<int> low(n); // stores the lowest time of all of its adjacent nodes except parent
    vector<bool> vis(n, false);
    dfs(0, -1, low, tin, adj, vis, bridges);
    return bridges;
}
int main() {
    return 0;
}