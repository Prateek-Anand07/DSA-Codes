#include<iostream>
#include<climits>
using namespace std;
int main() {
    int n/*, maxNo=INT_MIN*/;
    cout<<"enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    // To find maximum element in array
    // for(int i=0; i<n; i++) {
    //     maxNo = max(maxNo, arr[i]);
    //     cout<<"max till "<<i<<" is "<<maxNo<<endl;
    // }
    // To print sum of every sub array of an array
    // for(int i=0; i<n; i++) {
    //     int current = 0;
    //     for(int j=i; j<n; j++) {
    //         current += arr[j];
    //         cout<<current<<endl;
    //     }
    // }
    // To print length of maximum size of arithmetic subarray
    int ans = 2;
    int pd = arr[1]-arr[0];
    int current = 2;
    int j = 1;
    while(j<n-1) {
        if(pd == arr[j+1]-arr[j]) 
            current++;
        else {
            pd = arr[j+1]-arr[j];
            current = 2;
        }
        ans = max(ans, current);
        j++;
    }
    cout<<ans;
    // Q3
    // int arr[n+1];
    // arr[n] = -1;
    // for(int i=0; i<n; i++) {
    //     cin>>arr[i];
    // }
    // if(n==1) {
    //     cout<<"1";
    //     return 0;
    // }
    // int mx = -1, ans = 0;
    // for(int i=0; i<n; i++) {
    //     if(arr[i]>mx && arr[i]>arr[i+1]) {
    //         ans++;
    //     }
    //     mx = max(mx, arr[i]);
    // }
    // cout<<ans;
    return 0;
}