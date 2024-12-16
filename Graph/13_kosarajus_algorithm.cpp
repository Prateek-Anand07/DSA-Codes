#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for(auto it: adj[node]) {
        if(!vis[it])
            dfs(adj, it, vis, st);
    }
    st.push(node);
}
void dfsSCC(vector<vector<int>>& adjR, int node, vector<bool>& vis) {
    vis[node] = true;
    for(auto it: adjR[node]) {
        if(!vis[it]) 
            dfsSCC(adjR, it, vis);
    }
}
// Kosaraju's algorithm
// It can be applied on directed graph only
// Time complexity: 3*O(V+E)
// Space complexity: 2*O(V+E)+O(2V)
int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    stack<int> st;
    // Step 1: To sort the edges according to finishing time
    // it is required to know which node is in scc1
    for(int i=0; i<n; i++) {
        if(!vis[i])
            dfs(adj, i, vis, st);
    }
    // Step 2: To reverse all edges
    // it is done as in scc nothing effected but it prevent to traverse from one scc to another scc
    vector<vector<int>> adjR(n);
    for(int i=0; i<n; i++) {
        vis[i] = false; // visited is marked false to use it again
        for(auto it: adj[i]) {
            adjR[it].push_back(i);
        }
    }
    // Step 3: Again DFS
    // To count or print scc
    int cnt = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            dfsSCC(adjR, node, vis);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    return 0;
}