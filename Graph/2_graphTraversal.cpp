#include<bits/stdc++.h>
using namespace std;
// BFS
vector<int> bfsOfGraph(vector<vector<int>> &adj) { // Time complexity: O(N)+O(2E) ~ O(N+E)
    int n = adj.size();                             // Space complexity: O(3N) ~ O(N)
    vector<bool> visited(n, false); // O(N)
    queue<int> q; // O(N)
    q.push(0);
    visited[0] = true;
    vector<int> bfs; // O(N)
    while(!q.empty()) { // run for each nodes so n times
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]) { // it runs for every neighbours of each node so degree times of each node and total degree is 2E
            if(!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return bfs;
}


// DFS
void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, vector<int>& ls) {
    vis[node] = true;
    ls.push_back(node);
    for(auto it: adj[node]) {
        if(!vis[it]) 
            dfs(adj, it, vis, ls);
    }
}
vector<int> dfsOfGraph(vector<vector<int>>& adj) { // Space complexity: O(3N) ~ O(N)  - (dfs, vis, recursion stack space)
// Time complexity: O(N)+O(2E) ~ O(N+E)
    vector<int> ls;
    vector<bool> vis(adj.size(), false);
    int start = 0;
    dfs(adj, start, vis, ls);
    return ls;
}
int main() {
    int n, m; // n: no. of nodes & m: no. of edges
    cin>>n>>m;
    vector<vector<int>> adjacencyList(n); // n if 0-base indexing and n+1 if 1-base indexing
    for(int i=0; i<m; i++) {
        int x, y;
        cin>>x>>y; // x & y are two pairs which are edged
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x); // if graph is directed don't write this line
    }
    vector<int> bfs = bfsOfGraph(adjacencyList);
    for(auto it: bfs)
        cout<<it<<" ";
    return 0;
}