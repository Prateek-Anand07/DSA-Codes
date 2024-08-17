#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    //Bubble sort
    // for(int i=0; i<n-1; i++) {
    //     for(int j=0; j<n-1-i; j++) {
    //         if(arr[j]>arr[j+1]) {
    //             int swap = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = swap;
    //         }
    //     }
    // }
    // Insetion sort
    for(int i=1; i<n; i++) {
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}