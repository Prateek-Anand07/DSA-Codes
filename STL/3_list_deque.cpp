#include<bits/stdc++.h>
using namespace std;
int main() {
    // List is same as vector here we can perform front operation as well
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}
    ls.push_front(5); // {5, 2, 4}
    ls.emplace_front(6); // {6, 5, 2, 4}
    // for(auto element: ls) {
    //     cout<<element;
    // }
    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap


    // Deque:
    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4); // {4, 1, 2}
    dq.emplace_front(3); // {3, 4, 1, 2}
    
    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4, 1}
    cout<<dq.back(); // 1
    cout<<dq.front(); // 4
    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
    return 0;
}