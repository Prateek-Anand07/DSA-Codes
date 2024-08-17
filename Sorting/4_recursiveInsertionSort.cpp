#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int i, int n) {
    // Time complexity for average and worst case is O(N^2)
    //    but time complexity in best case when array is sorted is O(N)
    if(i==n)
        return;
    int j = i;
    while(j>0 && arr[j-1]>arr[j]) {
        swap(arr[j-1], arr[j]);
        j--;
    }
    insertionSort(arr, i+1, n);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    insertionSort(arr, 0, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}