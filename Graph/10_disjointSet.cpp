// Disjoint set: Find two nodes are disjoint in constant time
#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++) {
                parent[i] = i;
            }
        }
        int findUParent(int node) {
            if(parent[node] == node)
                return node;
            return parent[node] = findUParent(parent[node]); // Path compression
        }
        void unionByRank(int u, int v) {
            int up_u = findUParent(u), up_v = findUParent(v);
            if(up_u == up_v)
                return;
            if(rank[up_u] < rank[up_v]) 
                parent[up_u] = up_v;
            else if(rank[up_u] > rank[up_v])
                parent[up_v] = up_u;
            else {
                parent[up_u] = up_v;
                rank[up_v]++;
            }
        }
        void unionBySize(int u, int v) {
            int up_u = findUParent(u), up_v = findUParent(v);
            if(up_u == up_v)
                return;
            if(size[up_u] < size[up_v]) {
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            }
            else {
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }
};

// Kruskal's algorithm - To find Minimum spanning tree(MST) and it's weight sum
// it uses disjoint set data structure to find mst
// Time complexity: O(V+E)+O(E*log(E))+O(E*4*alpa*2) ~ O(E*log(E)) ~ O(E*log(V))
// Space complexity: O(2*V+E) ~ O(V+E) : 2 vectors in disjoint set class and E for storing edges
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<V; i++) { // O(V+E)
        for(auto it: adj[i]) {
            int wt = it[1];
            int adjNode = it[0];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(), edges.end()); // O(E*log(E))
    int mst = 0;
    for(auto it: edges) { // O(E)
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUParent(u) != ds.findUParent(v)) { // O(4*alpa*2)
            mst += wt;
            ds.unionBySize(u, v);
        }
    }
    return mst;
}
int main() {
    // O(4 alpha) ~ O(1) time complexity
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}