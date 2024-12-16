// Floyd Warshal Algorithm (multi source shortest path algorithm)
// we have to find shortest path between any two nodes
// it helps to detect negative cycle
#include <bits/stdc++.h>
using namespace std;

void shortestDistance(vector<vector<int>>& mat) { // mat is a adjacency matrix containing edge weights and if nodes are not reachable then it contains -1 there
// Time complexity: O(N^3)
// Space complexity: O(N^2)
// mat is adjacency matrix for directed graph
    int n = mat.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == -1)
                mat[i][j] = 1e9;
            if(i == j)
                mat[i][j] = 0;
        }
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
    // This algorithm also help us to detect negative cycle
    for(int i=0; i<n; i++) {
        if(mat[i][i] < 0) {
            cout<<"Negative cycle is present in graph";
            return;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == 1e9)
                mat[i][j] = -1;
        }
    }
}
// for such multi source questions we can also implement Dijkastra's algorithm by doing for each node but graph should not contain negative cycle
// in that case time complexity will be less than this
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> dist(adj.size(), 1e9);
    dist[src] = 0;
    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]) {
            if(distance+it.second < dist[it.first]) {
                dist[it.first] = distance+it.second;
                pq.push({distance+it.second, it.first});
            }
        }
    }
    return dist;
}
// Time complexity: O(V*E*log(V))
// Space complexity: O(V*(V+E)) 
// as it is taking that much space each time when running for each node
// better when graph doesn't contain negative cycle and have large number of nodes
void shortestDistanceDijkastra(vector<vector<int>>& mat) { // mat is a adjacency matrix containing edge weights and if nodes are not reachable then it contains -1 there
    int n = mat.size();
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j]!=-1 && i!=j)
                adj[i].push_back({j, mat[i][j]});
        }
    }
    for(int i=0; i<n; i++) {
        vector<int> dist = dijkstra(adj, i);
        for(int j=0; j<n; j++) {
            if(dist[j] == 1e9)
                mat[i][j] = -1;
            else
                mat[i][j] = dist[j];
        }
    }
}
int main() {
    return 0;
}