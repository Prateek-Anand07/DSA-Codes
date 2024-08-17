#include<bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> pq; // largest will be at top
    // called max heap
    pq.push(5); // {5}
    pq.push(2); // {5, 2}, operates in log n
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}
    
    // cout<<pq.top(); // 10, operates in O(n)
    pq.pop();; // {8, 5, 2}, operates in log n
    // size swap empty function same as others


    // min heap:
    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(5); // {5}
    pqm.push(2); // {2, 5}
    pqm.push(8); // {2, 5, 8}
    pqm.emplace(10); // {2, 5, 8, 10}
    // cout<<pqm.top(); // prints 2
    pqm.pop(); // {5, 8, 10}
    cout<<pqm.top(); // 5
    return 0;
}