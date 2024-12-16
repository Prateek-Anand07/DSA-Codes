// Prim's algorithm - To find Minimum spanning tree(MST) and it's weight sum
#include <bits/stdc++.h>

// Time complexity: O(E*log(V)) or O(E*log(E))
// Space complexity: O(V+E)
int spanningTree(int V, vector<vector<int>> adj[]) { // The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers.
    vector<int> vis(V, false); // V                    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // E
    pq.push({0, 0});
    int sum = 0; // Push+Pop
    // overall: E*log(E)+E*log(E) ~ E*log(E) = E*log(V^2) ~ E*log(V): as in case of complete graph E = V^2
    // E                                        
    while(!pq.empty()) {
        auto it = pq.top(); // log(E)
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if(vis[node])
            continue;
        vis[node] = 1;
        sum += wt;
        // if we have to make mst then we put parent node also in pq and here we put edges in mst
        for(auto curr: adj[node]) { // E
            int adjnode = curr[0];
            int edW = curr[1];
            if(!vis[adjnode])
                pq.push({edW, adjnode}); // log(E)
        }
    }
    return sum;
}
using namespace std;
int main() {
    return 0;
}