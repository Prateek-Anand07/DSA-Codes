#include<bits/stdc++.h>
using namespace std;
bool detect(vector<vector<int>>& adj, int node, vector<bool>& vis) {
    vis[node] = true;
    queue<pair<int, int>> q;
    q.push({node, -1});
    while(!q.empty()) {
        int src = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[src]) {
            if(!vis[it]) {
                q.push({it, src});
                vis[it] = true;
            }
            else if(parent != it)
                return true;
        }
    }
    return false;
}
// Detection by BFS (for undirected graph)
bool isCycle(vector<vector<int>>& adj) {       // Time complexity: O(N+E)
    vector<bool> visited(adj.size(), false);   // Space complexity: O(N)
    for(int i=0; i<adj.size(); i++) {
        if(!visited[i]) {
            if(detect(adj, i, visited))
                return true;
        }
    }
    return false;
}

bool detect(vector<vector<int>>& adj, vector<bool>& vis, int node, int& parent) {
    vis[node] = true;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(detect(adj, vis, it, node))
                return true;
        }
        else if(it != parent)
            return true;
    }
    return false;
}
// Detection by DFS in directed graph
bool isCycle(vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(), false);
    int parent = -1;
    for(int i=0; i<adj.size(); i++) {
        if(!vis[i]) {
            if(detect(adj, vis, i, parent))
                return true;
        }
    }
    return false;
}

bool dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
    vis[node] = 2;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(dfs(adj, vis, it))
                return true;
        }
        else if(vis[it] == 2)
            return true;
    }
    vis[node] = 1;
    return false;
}
// Detection by DFS in directed graph
bool detectCycle(vector<vector<int>>& adj) { // Time complexity: O(N+E)
    int n = adj.size();                      // Space complexity: O(N) 
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            if(dfs(adj, vis, i))
                return true;
        }
    }
    return false;
}

// Detection by Kahn's algorithm for directed graph (BFS)
bool isCyclic(int V, vector<vector<int>> adj) { // Time complexity: O(V+E)                
    vector<int> indegree(V, 0);                 // Space complexity: O(2V)
    queue<int> q;
    for(int i=0; i<V; i++) {
    for(auto it: adj[i])
        indegree[it]++;
    }
    for(int i=0; i<V; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        cnt++;
        for(auto it: adj[top]) {
            indegree[it]--;
            if(indegree[it] == 0)
            q.push(it);
        }
    }
    if(cnt == V)
        return false; 
    return true;
}
int main() {
    int n, m; // n: no. of nodes & m: no. of edges
    cin>>n>>m;
    vector<vector<int>> adjacencyList(n); // n if 0-base indexing and n+1 if 1-base indexing
    for(int i=0; i<m; i++) {
        int x, y;
        cin>>x>>y; // x & y are two pairs which are edged
        adjacencyList[x].push_back(y);
    }
    cout<<(detectCycle(adjacencyList) ? "Cycle detected" : "No cycle detected")<<endl;
    return 0;
}