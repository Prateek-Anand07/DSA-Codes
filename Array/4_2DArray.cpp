#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    // Searching in 2D array
    // int x, i, j;
    // cout<<"enter element to search: ";
    // cin>>x;
    // for(i=0; i<n; i++) {
    //     for(j=0; j<m; j++) {
    //         if(arr[i][j]==x) {
    //             cout<<"element found\n";
    //             return 0;
    //         }
    //     }
    // }
    // if(i==n)
    //     cout<<"element not found";

    // Spiral printing of array elements
    int row_start=0, row_end=n-1, col_start=0, col_end=m-1;
    while(row_start<=row_end && col_start<=col_end) {
        // Print top row
        if(row_start<=row_end) {
            for (int col = col_start; col <= col_end; col++)
                cout << arr[row_start][col] << " ";
            row_start++; 
        }

        // Print last column
        if(col_start<=col_end) {
            for (int row = row_start; row <= row_end; row++)
                cout << arr[row][col_end] << " ";
            col_end--; 
        }

        // Print bottom row
        if (row_start <= row_end) {
            for (int col = col_end; col >= col_start; col--)
                cout << arr[row_end][col] << " ";
            row_end--;
        }

        // Print first column
        if (col_start <= col_end) {
            for (int row = row_end; row >= row_start; row--)
                cout << arr[row][col_start] << " ";
            col_start++;
        }
    }
    return 0;
}