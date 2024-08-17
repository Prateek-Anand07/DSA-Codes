#include<bits/stdc++.h>
using namespace std;
// comparator function:
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second) 
        return true;
    if(p1.second > p2.second)
        return false;
    // if they are same
    if(p1.first > p2.first)
        return true;
    return false;
}
int main() {
    int a[] = {1, 5, 3, 2};
    int n = 4;
    sort(a, a+n); // sorting of array
    // initial and next to last pointer 
    // For vector: sort(v.begin(), v.end());
    sort(a+2, a+4); // applied to {3, 2}
    sort(a, a+n, greater<int>()); // to sort in descending order {5, 3, 2, 1}
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    int n=2;
    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending
    sort(a, a+n, comp);

    int num = 7;
    int cnt = __builtin_popcount(num);// number of 1 in binary form

    long long m = 165786578687;
    int cnt = __builtin_popcountll(m); // for long long number

    string s = "123"; // start from sorted to get all permutation
    sort(s.begin(), s.end());
    do{
        cout<<s<<endl; // for all permutations
    } while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a, a+n); // for maximum element
    return 0;
}