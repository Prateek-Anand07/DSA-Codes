#include<bits/stdc++.h>
using namespace std;
int main() {
    // stack: LIFO(last in first out)
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout<<st.top(); // print 5
    // indexing is not valid in stack
    st.pop(); // {3, 3, 2, 1}
    cout<<st.size(); // 4
    cout<<st.empty(); // 0
    // stack<int> st1, st2;
    // st1.swap(st2);
    // All operations in O(1)

    // Queue: FIFO (first in first out)
    // queue<int> q;
    // q.push(1); // {1}
    // q.push(2); // {1, 2}
    // q.emplace(4); // {1, 2, 4}

    // q.back() += 5; // last:4+=5
    // cout<<q.back(); // 9
    // Q is {1, 2, 9}
    // cout<<q.front(); // 1
    // q.pop(); // {2, 9}
    // cout<<q.front(); // 2
    // size swap empty same as stack
    // All operations in O(1)
    return 0;
}