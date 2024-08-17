#include<iostream>
using namespace std;
// Time complexity: O(N)
void countSort(int arr[], int n) { // can't be used for negative integers
    int k = arr[0];
    for(int i=0; i<n; i++) {
        k=max(k, arr[i]);
    }
    int count[k+1] = {0};
    // Stored count of each element:
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    // Stored position of each element with 1 indexing:
    for(int i=1; i<=k; i++) {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--) {
        output[--count[arr[i]]] = arr[i]; // Put elements at their exact position and first reducing 1 to manage 
                                            // repeating elements
    }
    for(int i=0; i<n; i++) {
        arr[i] = output[i];
    }
}
int main() {
    int arr[] = {6,1,3,12,0,4,5,9,9};
    countSort(arr, 9);
    for(int i=0; i<9; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}