#include<iostream>
using namespace std;
// to find a unique number where all are repeating except one
// int uniqueNo(int arr[], int n) {
//     int xorSum = 0;
//     for(int i=0; i<n; i++){
//         xorSum = xorSum^arr[i];
//     }
//     return xorSum;
// }
// to find two unique number where all are repeating except two
bool getBit(int n, int pos) {
    return ((n & (1<<pos))!=0);
}
// void unique(int arr[], int n) {
//     int xorSum=0;
//     for(int i=0; i<n; i++) {
//         xorSum = xorSum^arr[i];
//     }
//     int tempxor = xorSum, setbit = 0, pos = 0;
//     while(setbit!=1) {
//         setbit = xorSum & 1;
//         pos++;
//         xorSum = xorSum>>pos;
//     }
//     int newxor=0;
//     for(int i=0; i<n; i++) {
//         if(getBit(arr[i],pos-1)) {
//             newxor = newxor^arr[i];
//         }
//     }
//     cout<<newxor<<endl;
//     cout<<(tempxor^newxor)<<endl;
// }
// to find a unique number where all are repeating three times
int setBit(int n, int pos) {
    return (n | (1<<pos));
}
int unique(int arr[], int n) {
    int result = 0;
    for(int i=0; i<64; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(getBit(arr[j], i)) {
                sum++;
            }
        }
        if(sum%3!=0) {
            result = setBit(result, i);      
        }
    }
    return result;
}
int main() {
    // int arr[] = {1,2,3,2,1,5,3,5,4};
    // cout<<uniqueNo(arr, 9);
    // int arr[] = {1,4,2,3,1,2,6,3};
    // unique(arr, 8);
    int arr[] = {1,2,3,4,1,2,3,1,2,3};
    cout<<unique(arr, 10);
    return 0;
}