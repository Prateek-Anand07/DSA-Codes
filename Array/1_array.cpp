#include <bits/stdc++.h>
using namespace std;
int main() {
    // int n;
    // cout<<"enter size of array: ";
    // cin>>n;
    // int arr[n];
    // for(int i=0; i<n; i++) {
    //     cin>>arr[i];
    // }
    // int maxNo = INT_MIN;
    // int minNo = INT_MAX;
    // for(int i=0; i<n; i++) {
    //     maxNo = max(maxNo, arr[i]);
    //     minNo = min(minNo, arr[i]);
    // }
    // cout<<minNo<<" "<<maxNo;

    // Partial sorting approach:
    vector<int> vec = {7, 4, 3, 5, 6};
    int l = vec.size();
    nth_element(begin(vec), begin(vec)+l/2, end(vec)); // sorts partially: just sort the array from l/2th position to last and other positions are not correct
    // vec become: {4, 3, [5, 6, 7]}
    // average time complexity: O(l)
    // worst case time complexity: O(l*log l)
    cout<<"vec:"<<endl;
    for(auto it: vec)
        cout<<it<<" ";
    return 0;
}