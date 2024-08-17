#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n) {
    // Time complexity for average and worst case is O(N^2)
    if(n==1) {
        return;
    }
    int didSwap = 0;
    for(int i=0; i<n-1; i++) {
        if(arr[i]>arr[i+1]) {
            swap(arr[i], arr[i+1]);
            didSwap = 1;
        }
    }
    if(didSwap==0) // but time complexity in best case when array is sorted is O(N)
        return;
    bubbleSort(arr, n-1);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}