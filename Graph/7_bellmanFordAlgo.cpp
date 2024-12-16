// Bellman Ford Algorithm
// it does work for negative weight
// it only works for directed graph
// helps to detect negative cycle 
// for undirected graph convert it to directed by two edges between same two nodes
#include <bits/stdc++.h>

// if it contains negative cycle it will return an array containing only -1
// if any node can't be reached then in that place it will return 1e8
// Time complexity: O(V*E) : which is more than Dijkastra's Algorithm but it is used when graph has negative cycle
// Space complexity: O(V)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) { // edges can be any order
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for(int i=0; i<V-1; i++) { // we have to relax edges for V-1 times as in worst case src is at last and 2nd element is at last 2nd then it takes V-1 times relaxation
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]) // relaxation
                dist[v] = dist[u]+wt;
        }
    }
    // one last relaxation to check negative cycle
    // as any directed graph can only be relaxed V-1 times and if it would be relaxed in any case then it would definetly be containing negative cycle since value will keep on decreasing in that case
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]) 
            return {-1}; // if it gets relaxed
    }
    return dist;
}
using namespace std;
int main() {
    return 0;
}