// Topo sort is only applicable for direct acyclic graph(DAG)
// In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st, int node) {
    vis[node] = true;
    for(auto it: adj[node]) {
        if(!vis[it])
            dfs(adj, vis, st, it);
    }
    st.push(node);
}
// Topo sort by DFS
vector<int> topologicalSort(vector<vector<int>>& adj) { // Time complexity: O(N+E)
    int n = adj.size();                                 // Space complexity: O(3N)
    vector<bool> vis(n, false);
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(!vis[i])
            dfs(adj, vis, st, i);
    }
    vector<int> v;
    while(!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}

// Topo sort by BFS or Kahn's algorithm
vector<int> topologicalSortbyKahnsAlgo(vector<vector<int>>& adj) { // Time complexity: O(N+E)
    int n = adj.size();                                             // Space complexity: O(3N)
    vector<int> indegree(n, 0);
    queue<int> q;
    for(int i=0; i<n; i++) {
        for(auto it: adj[i])
            indegree[it]++;
    }
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        topo.push_back(top);
        for(auto it: adj[top]) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}
int main() {
    return 0;
}