#include <bits/stdc++.h>
using namespace std;
void subsequence(string s, int ind, string str, vector<string>& ans) {
    if(ind == s.size()) {
        ans.push_back(str);
        return;
    }
    subsequence(s, ind+1, str, ans);
    str += s[ind];
    subsequence(s, ind+1, str, ans);
}
int main() {
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    vector<string> ans;
    subsequence(s, 0, "", ans);
    for(string str : ans)
        cout<<str<<" ";
    return 0;
}