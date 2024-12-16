#include <bits/stdc++.h>
using namespace std;
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
    // Space complexity: O(2E) where E is no. of edges (in case of undirected graph)
    // Space complexity: O(E) (in case of directed graph)
    // if edges have weight then they will be stored in array as pair then list will be like vector<vector<pair<int, int>>> adjacencyList
    for(auto first: adjacencyList) {
        for(auto second: first) {
            cout<<second<<",";
        }
        cout<<endl;
    }
    return 0;
}