#include<bits/stdc++.h>
using namespace std;
int main() {
    // Pairs: to store two quantities in one variable
    pair<int, int> p = {1, 4};
    cout<<p.first<<" and "<<p.second<<endl;
    pair<int, pair<int, int>> q = {1, {4, 33}};
    cout<<p.first<<" "<<q.second.first<<" "<<q.second.second;
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {3, 1}}; // Pair array
    cout<<arr[1].second;
    return 0;
}