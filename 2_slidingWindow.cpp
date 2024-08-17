#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int s=0, ans=INT_MAX;
    for(int i=0; i<k; i++) {
        s+=arr[i];
    }
    cout<<s<<" ";
    ans = min(ans, s);
    // sliding window technique
    for(int i=1; i<n-k+1; i++) {
        s -= arr[i-1];
        s += arr[i+k-1];
        ans = min(ans, s);
        cout<<s<<" ";
    } 
    cout<<endl<<"Minimum window value is "<<ans;
    return 0;
}