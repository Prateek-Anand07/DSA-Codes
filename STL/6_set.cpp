#include<bits/stdc++.h>
using namespace std;
int main() {
    // set stores everything in sorted and unique order
    set<int>st;
    st.insert(1); // {1}
    st.insert(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3 , 4}
    cout<<st.size(); 

    // st = {1, 2, 3, 4, 5}
    auto it = st.find(3); // points to iterator which points 3
    auto it = st.find(6); // DNE so points to st.end()
    st.erase(5); // erase 5, takes log n time

    int cnt = st.count(1); // if 1: present:1, absent:0

    auto it = st.find(3);
    st.erase(it); // it takes constant time deletes 3

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)
    // everything hapens in log n

    // FOR SETS SYNTAX:
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    // lower_bound function: that STL which points to the first occurence of an element if it occur
    //  otherwise it points to the iterator pointing element next greater to that
    int a[] = {1, 4, 5, 6, 9, 9};
    int n = 6;
    int ind = lower_bound(a, a+n, 4) - a; // 2-1
    int ind = lower_bound(a, a+n, 7) - a; // 5-1
    int ind = lower_bound(a, a+n, 10) - a; // 7-1
    // for vector:
    // int ind = lower_bound(a.begin(), a.end(), x) - a.begin();

    // upper_bound function: it points to the iterator pointing next greater element
    int a[] = {1, 4, 5, 6, 9, 9};
    int ind = upper_bound(a, a+n, 4) - a;
    // for vector:
    // int ind = upper_bound(a.begin(), a.end(), x) - a.begin();
    // operates in log n


    // Multiset: sorted occurence
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1); // number of occurence of 1
    
    ms.erase(ms.find(1)); // only single 1 erased
    // rest all functions same as set


    // unorderd set: unique occurence
    unordered_set<int> st;
    // generally O(1)
    // lower_bound and upper_bound function does not works and rest functions are same
    return 0;
}