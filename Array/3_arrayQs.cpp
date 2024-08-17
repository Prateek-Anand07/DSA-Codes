#include <bits/stdc++.h>
using namespace std;
int main() {
    // Q.1 find index of first occurence of a repetive element in an array
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    // const int N = 100000;
    // int idx[N];
    // for(int i=0; i<N; i++) {
    //     idx[i] = -1;
    // }
    // int minidx = INT_MAX;
    // for(int i=0; i<n; i++) {
    //     if(idx[arr[i]]!=-1) {
    //         minidx = min(minidx, idx[arr[i]]);
    //     }
    //     else {
    //         idx[arr[i]] = i;
    //     }
    // }
    // if(minidx==INT_MAX)
    //     cout<<"-1";
    // else
    //     cout<<minidx+1;
    // Q.2. Subarray with given sum
    int s;
    cin>>s;
    int i=0, j=0, st=-1, en=-1, sum=0;
    while(j<n && sum+arr[j]<=s) {
        sum+=arr[j];
        j++;
    }
    if(sum==s) {
        cout<<i+1<<" "<<j;
        return 0;
    }
    while(j<n) {
        sum+=arr[j];
        while(sum>s) {
            sum-=arr[i];
            i++;
        }
        if(sum==s) {
            st = i+1;
            en = j+1;
            break; 
        }
        j++;
    }
    cout<<st<<" "<<en;
    return 0;
}