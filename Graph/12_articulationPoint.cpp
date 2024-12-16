#include <bits/stdc++.h>
using namespace std;
int timer = 1;
void dfs(int node, int parent, vector<int> adj[], vector<bool>& vis, vector<int>& tin, vector<int>& low, vector<bool>& marked) {
    vis[node] = true;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it: adj[node]) {
        if(it == parent)
            continue;
        if(!vis[it]) {
        dfs(it, node, adj, vis, tin, low, marked);
        low[node] = min(low[node], low[it]);
        if(low[it]>=tin[node] && parent!=-1) // logic can't be applied for starting node whose parent is -1
            marked[node] = true; // as same node can come multiple times in traversal as articulation points so we use hashing technique and just mark those nodes 
            child++; // only if it is not visited
        }
        else {
            low[node] = min(low[node], tin[it]); // if visited minimum will be taken with tin[adjacent node]
        }
    }
    if(child>1 && parent==-1) // if parent is -1 then they will be articulation point it they have more than 1 child which are not connected in themselves and that will be checked as we increase child if it is not visited
        marked[node] = true;
}
// Articulation Points: Points on which removing graph breaks into multiple components
// Time complexity: O(V+2E) (same as DFS)
// Space complexity: O(4V)
vector<int> articulationPoints(int V, vector<int>adj[]) {
    vector<int> points;
    vector<bool> vis(V, false);
    vector<int> tin(V);
    vector<int> low(V); // to store lowest of adjacent nodes except parent & visited
    vector<bool> marked(V);
    dfs(0, -1, adj, vis, tin, low, marked);
    for(int i=0; i<V; i++) {
        if(marked[i])
            points.push_back(i);
    }
    if(points.size() == 0)
        return {-1};
    return points;
}
int main() {
    return 0;
}