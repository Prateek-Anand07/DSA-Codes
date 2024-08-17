#include<bits/stdc++.h>
using namespace std;
int main() {
    // Map: stores unique keys in sorted order
    // map syntax:
    // map<key, value>
    map<int, int> mpp;
    // map<int, pair<int,int>> mpp;
    // map<pair<int,int>, int> mpp;
    // Considering: map<int, int> mpp
    mpp[1] = 2; // key = 2 // {1, 2}
    mpp.insert({3, 1});
    mpp.insert({2, 4}); // [{1, 2}, {2, 4}, {3, 1}]
    // Considering: map<pair<int,int>, int> mpp
    // mpp[{2,3}] = 10;
    // For: [{1, 2}, {2, 4}, {3, 1}]
    for(auto it: mpp) {
        cout<<it.first<<" "<<it.second<<endl;
    } // print 1 2
      //       2 4
     //        3 1 
    // map stores in sorted order of key
    // cout<<mpp[1]; // 2
    // cout<<mpp[5]; // 0 or NULL
    cout<<mpp.size();
    // auto it = mpp.find(3); // points to iterator pointing key 3
    // cout << it->second;

    // auto it = mpp.find(5); // DNE so points to mpp.end()

    // auto it = mpp.lower_bound(2);
    // auto it = mpp.upper_bound(3);

    // erase, swap, size, empty are same as others
    // map works in log n time


    // Multimap: can store duplicate keys but in sorted order


    // Unordered map:stores unique keys in unsorted order
    //      works in O(1) time
    return 0;
}