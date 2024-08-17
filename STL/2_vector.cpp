#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
bool myCompare(pair<int,int> p1, pair<int,int> p2) {
    return p1.first<p2.first;
}
int main()
{
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3); // elements are added one by one
    // v.pop_back();  // Removes last element
    // vector<int>::iterator it;  // iterator works as pointer
    // for (it = v.begin(); it != v.end(); it++) // first method to print, v.end() element doesn't exist, it points to the element next to the last element
    //     cout << *it << endl;
    // vector<int> v1;
    // v1.push_back(20);
    // v1.push_back(21);
    // v1.push_back(23);
    // swap(v, v1);
    // v.swap(v1); // two methods of swapping values of vectors
    // for(auto element:v) // Second method to print
    //     cout<<element<<endl;
    // for(auto element:v1)
    //     cout<<element<<endl;
    // for(int i=0; i<v.size(); i++) // Third method to print
    //     cout<<v[i]<<" ";
    // vector<int> v2 = {2, 12, 1, 3, 4, 8, 6, 5}; // Another way of initializing vectors
    // vector<int> v2(4); // a vector of size 4 with all elements zero
    // for(int i=0; i<3; i++) {
    //     cout<<v2[i]<<endl; // vectors are initialy given value equal to zero
    // }
    // for(int i=0; i<v2.size(); i++)
    //     cout<<v2[i]<<" ";
    // cout<<endl;
    // sort(v2.begin(), v2.end());
    // for(int i=0; i<v2.size(); i++)
    //     cout<<v2[i]<<" ";
    // int sum = accumulate(v1.begin(), v1.end(), 0);
    // cout << sum << endl;
    // int mx = *max_element(v2.begin(), v2.end());
    // cout << mx << endl;
    // int mn = *min_element(v2.begin(), v2.end());
    // cout << mn << endl;
    // partial_sum(v2.begin(), v2.end(), v2.begin());
    // for (int i = 0; i < v2.size(); i++)
    //     cout << v2[i] << " ";
    // Q. To put 0 on minimum position element and 1,2,3.... so on
    // int arr[] = {10,16,7,14,5,3,12,9};
    // vector <pair<int,int>> a;
    // for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) {
    //     a.push_back(make_pair(arr[i],i));
    // }
    // sort(a.begin(), a.end(), myCompare);
    // for(int i=0; i<a.size(); i++) {
    //     arr[a[i].second] = i;
    // }
    // for(int i=0; i<a.size(); i++)
    //     cout<<arr[i]<<" ";
    // vector<vector<int>> matrix = {{1,2}, {3,4}};
    // for(auto row: matrix) {
    //     for(auto element: row) { // iterating through 2d vectors
    //         cout<<element<<" ";
    //     }
    // }
    // Erasing:
    // vector<int> v = {10, 20, 12, 23};
    // v.erase(v.begin()+1); // delete 20
    vector<int> v = {10, 20, 12, 23, 35, 36};
    v.erase(v.begin()+2, v.begin()+4); // delete 12 and 23
    // result = {10. 20. 35, 36}
    // Insert function:
    vector<int>a(2, 100); // {100, 100}
    a.insert(a.begin(), 300); // {300, 100, 100}
    a.insert(a.begin()+1, 2, 10); // {300, 10, 10, 100, 100}
    vector<int>copy(2, 50); // {50, 50}
    a.insert(a.begin(), copy.begin(), a.end()); // {50, 50, 300, 10, 10, 100, 100}
    a.clear(); // erases the entire vector
    cout<<a.empty(); // 1 if vector is empty otherwise 0
    return 0;
}