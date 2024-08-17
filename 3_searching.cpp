#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) { // array must be sorted
    for(int i=0; i<n; i++) {
        int beg=0, end=n-1;
        int middle= (beg+end)/2;
        while(beg<=end) {
            if(arr[middle]>key)
                end = middle-1;
            else if(arr[middle]<key)
                beg = middle+1;
            else
                return middle;
            middle = (beg+end)/2;
        }
    }
}
int main() {
    //Linear search(time complexity is O(n))
    int n, i;
    cout<<"enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int key;
    cout<<"enter element to search: ";
    cin>>key;
    // for(i=0; i<n; i++) {
    //     if(arr[i]==key) {
    //         cout<<"element found";
    //         break;
    //     }
    // }
    // if(i==n)
    //     cout<<"element not found";
    cout<<binarySearch(arr, n, key);
    //Binary search time complexity is O(log n)
    return 0;
}