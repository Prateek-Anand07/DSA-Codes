#include<bits/stdc++.h>
using namespace std;
string convert2binary(int n) { // Time Complexity = Space Complexity = O(log n)
    string res = "";
    while(n!=0) {
        if(n%2==1)
            res += '1';
        else
            res += '0';
        n/=2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int convert2decimal(string x) { // Time complexity = O(n)
    int n = x.length()-1;       // Space complexity = O(1)
    int p = 1;
    int num = 0;
    for(int i=n; i>=0; i--) {
        if(x[i] == '1') {
            num += p;
        }
        p *= 2;
    }
    return num;
}
int main() {
    cout<<convert2binary(6);
    // cout<<convert2decimal("1101");
    return 0;
}