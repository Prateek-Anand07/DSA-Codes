// Dijkastra's algoritm
// Dijkstra's Algorithm is a popular method used in graph-based data structures and algorithms (DSA) to find the shortest path between nodes in a weighted graph.
// it will not work if graph has edge having negative weight as in that case it will go into infinite loop
#include <bits/stdc++.h>
using namespace std;

// using priority queue
// Time complexity: O(E*log(V))
// Space complexity: O(V+E)
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> dist(adj.size(), INT_MAX);
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

// Using set
vector<int> dijkstraUsingSet(vector<vector<pair<int, int>>> &adj, int src) {
    set<pair<int, int>> st;
    vector<int> dist(adj.size(), INT_MAX);
    st.insert({0, src});
    dist[src] = 0;
    while(!st.empty()) {
        auto it = *(st.begin());
        int distance = it.first;
        int node = it.second;
        st.erase(it);
        for(auto it: adj[node]) {
            int adjNode = it.first;
            int edgeW = it.second;
            if(distance+edgeW < dist[adjNode]) {
                if(dist[adjNode] !=  INT_MAX) {
                    st.erase({dist[adjNode], adjNode});
                }
                st.insert({distance+edgeW, adjNode});
                dist[adjNode] = distance+edgeW;
            }
        }
    }
    return dist;
}
int main() {
    return 0;
}