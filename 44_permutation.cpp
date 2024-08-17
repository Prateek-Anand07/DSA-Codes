#include "bits/stdc++.h"
using namespace std;
// vector<vector<int>>ans;
// Q. Permutation of number having distinct number
// void permute(vector <int> &a, int idx) {
//     if(idx==a.size()) {
//         ans.push_back(a);
//         return;
//     }
//     for(int i=idx; i<a.size(); i++) {
//         swap(a[i], a[idx]);
//         permute(a, idx+1);
//         swap(a[i], a[idx]);
//     }
//     return;
// }
// Q. Permutation of number having repeating digits
void helper(vector<int> a, int idx, vector<vector<int>>&ans) {
    if(idx==a.size()) {
        ans.push_back(a);
        return;
    }
    for(int i=idx; i<a.size(); i++) {
        if((i!=idx) && (a[i]==a[idx])) 
            continue;
        swap(a[i], a[idx]);
        helper(a, idx+1, ans);
    }
    return;
}
vector<vector<int>> permute(vector<int>a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    helper(a, 0, ans);
    return ans;
}
int main() {
    int n;
    cin>>n;
    vector <int> a(n);
    for(auto &i: a) {
        cin>>i;
    }
    // permute(a,0);
    // sort(a.begin(), a.end());
    // do {
    //     ans.push_back(a);
    // } while(next_permutation(a.begin(), a.end()));
    // for(auto v: ans) {
    //     for(auto i: v) {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> res = permute(a);
    for(auto v: res) {
        for(auto i: v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
} 