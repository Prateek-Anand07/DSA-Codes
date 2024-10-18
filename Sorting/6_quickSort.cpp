#include<iostream>
using namespace std;
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1; // it will point to the last element less than pivot element
    for(int j=l; j<r; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}
void quickSort(int arr[], int l, int r) {
    if(l<r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}
int main() {
    int arr[] = {4,33,2,1,5,6};
    quickSort(arr, 0, 5);
    for(int i=0; i<6; i++) {
        cout<<arr[i]<<" ";
    } 
    return 0;
}