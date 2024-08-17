#include<iostream>
using namespace std;
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void dnfSort(int arr[], int n) {    // DNF: Dutch National Flag Sort
    int low=0, mid=0, high=n-1;
    while(mid<=high) {
        if(arr[mid]==0) {
            swap(arr, low, mid);
            low++; mid++;
        }
        else if(arr[mid]==1) {
            mid++;
        }
        else {
            swap(arr, mid, high);
            high--;
        }
    }
}
int main() {
    int arr[] = {0,0,2,1,1,0,0,2,2};
    dnfSort(arr, 9);
    for(int i=0; i<9; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}