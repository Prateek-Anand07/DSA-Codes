#include<bits/stdc++.h>
using namespace std;
void topoSort(vector<vector<pair<int, int>>>& adj, vector<bool>& vis, stack<int>& st, int node) {
    vis[node] = true;
    for(auto it: adj[node]) {
        if(!vis[it.first]) {
            topoSort(adj, vis, st, it.first);
        }
    }
    st.push(node);
}

// Find the shortes path to each vertex from index 0(src) in DAG and if can't reach then it will be -1
// Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
// edges[i][2] ~ weight for that edge
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) { 
    vector<vector<pair<int, int>>> adj(V);
    for(auto it: edges) {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<bool> vis(V, false);
    stack<int> st;
    topoSort(adj, vis, st, 0); // it doesn't go for connected components as we can't reach there if source is 0
    // if source is given then we have to start topoSort algo with that source
    vector<int> dist(V, INT_MAX);
    dist[0] = 0; // if source is given then we have to put src in place of 0
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        for(auto it: adj[node]) {
            if(dist[node]+it.second < dist[it.first])
                dist[it.first] = dist[node]+it.second;
        }   
    }
    for(int i=0; i<V; i++) {
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}
int main() {
    return 0;
}