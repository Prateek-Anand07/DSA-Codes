#include<iostream>
using namespace std;
bool sorted(int arr[], int n) {
    if(n==1)
        return true;
    else
        return arr[0]<arr[1] && sorted(arr+1, n-1);
}
void dec(int n) {
    if(n==1) {
        cout<<"1\n";
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
void inc(int n) {
    if(n==1) {
        cout<<"1\n";
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
int first(int arr[], int n, int i, int x) {
    if(i==n)
        return -1;
    if(arr[i]==x)
        return i;
    return first(arr, n, i+1, x);
}
int last(int arr[], int n, int i, int x) {
    if(i==n)
        return -1;
    int restArray = last(arr, n, i+1, x);
    if(restArray!=-1)
        return restArray;
    if(arr[i]==x)
        return i;
    return -1;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    // cout<<"Array is sorted: "<<sorted(arr, n);
    // dec(n);
    // inc(n);
    int x;
    cin>>x;
    cout<<first(arr, n, 0, x)<<endl;
    cout<<last(arr, n, 0, x);
    return 0;
}