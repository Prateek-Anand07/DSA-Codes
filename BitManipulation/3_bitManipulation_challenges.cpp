#include<iostream>
using namespace std;
// Write a program to check is a number power of 2
bool isPowerOf2(int n) {
    return (n && !(n & n-1));
}
// Check number of 1 in binary form
int numberOf1(int n) { 
    int count = 0;
    while(n!=0) { 
        n = n & (n-1);
        count++;
    }
    return count;
}
// Print all subsets of an array
void subsets(int arr[], int n) {
    for(int i=0; i<(1<<n); i++) {
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) 
                cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    // cout<<isPowerOf2(0)<<endl;
    // cout<<numberOf1(5)<<endl;
    int arr[3] = {1,2,3};
    subsets(arr, 3);
    return 0;
}