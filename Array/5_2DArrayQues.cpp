#include<iostream>
using namespace std;
int main() {
    // Transpose of matrix
    // int n;
    // cin>>n;
    // int arr[n][n];
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         int temp = arr[i][j];
    //         arr[i][j] = arr[j][i];
    //         arr[j][i] = temp; 
    //     }
    // }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // Multiplication of two matrix
    int a, b, s;
    cin>>a>>b>>s;
    // int m1[a][b], m2[b][c], mp[a][c];
    // for(int i=0; i<a; i++) {
    //     for(int j=0; j<b; j++) {
    //         cin>>m1[i][j];
    //     }
    // }
    // for(int i=0; i<b; i++) {
    //     for(int j=0; j<c; j++) {
    //         cin>>m2[i][j];
    //     }
    // }
    // for(int i=0; i<a; i++) {
    //     for(int j=0; j<c; j++) {
    //         mp[i][j] = 0;
    //         for(int k=0; k<b; k++) {
    //             mp[i][j] += m1[i][k]*m2[k][j];
    //         }
    //         cout<<mp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // Searching in each row sorted array
    int arr[a][b];
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            cin>>arr[i][j];
        }
    }
    bool flag = false;
    int r=0, c=b-1;
    while(r<a && c>=0) {
        if(arr[r][c]==s)
            flag = true;
        if(arr[r][c]>s)
            c--;
        else
            r++;
    }
    if(flag==true) 
        cout<<"Element found";
    else
        cout<<"Element not found";
    return 0;
}