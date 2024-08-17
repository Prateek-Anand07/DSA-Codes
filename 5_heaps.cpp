#include<bits/stdc++.h>
using namespace std;
class heap {
    public:
        int arr[100]; // implementation of heap by array
        int size;
        heap() {
            arr[0] = -1;
            size = 0;
        }
        void insert(int val) { // insertion in heap to create max-heap
            int ind = ++size;       // Time complexity: O(log n)
            arr[ind] = val;
            while(ind > 1) {
                int parent = ind/2;
                if(arr[parent] < arr[ind]) {
                    swap(arr[parent], arr[ind]);
                    ind = parent;
                }
                else {
                    return;
                }
            }
        }
        void print() {
            for(int i=1; i<=size; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void deleteRoot() { // deletion of root of max-heap
            if(size == 0)      // Time complexity: O(log n)
                return;
            arr[1] = arr[size]; // put last node value into root
            size--; // remove last node
            int i = 1;
            while(i < size) { // compare and put that node in correct position
                int leftchild = 2*i;
                int rightchild = 2*i+1;
                if(leftchild<=size && arr[i]<arr[leftchild]) {
                    swap(arr[leftchild], arr[i]);
                    i = leftchild;
                }
                if(rightchild<=size && arr[i]<arr[rightchild]) {
                    swap(arr[rightchild], arr[i]);
                    i = rightchild;
                }
                else {
                    return;
                }
            }
        }
};
// Heapify algorithm:
void heapify(int arr[], int n, int i) { // Time complexity: O(log n)
    int largest = i;
    int left=2*i, right=2*i+1;
    if(left<=n && arr[largest]<arr[left])
        largest = left;
    if(right<=n && arr[largest]<arr[right])
        largest = right;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        // Step 1:
        swap(arr[1], arr[size]);
        size--;
        // Step 2:
        heapify(arr, size, 1);
    }
}
int main() {
    // heap h;
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++) {
    //     int val;
    //     cin>>val;
    //     h.insert(val);
    // }
    // h.print();
    // h.deleteRoot();
    // h.print();
    int arr[] = {-1, 3, 23, 18, 6, 5, 3};
    int n = 6;
    // for(int i = n/2; i>0; i--) { // for n/2 -> 1 it is called and run for O(log i)
    //     heapify(arr, n, i);         // so there overall sum will be log 1 + log 2 + log 3 +....+ log n/2 = O(n)
    // }                   // Overall time complexity: O(n)
    // int arr[n];
    // for(int i=1; i<=n; i++) {
    //     cin>>arr[i];
    // }
    for(int i = n/2; i>0; i--) { // after this loop an array is converted into max-heap so any array can be 
        heapify(arr, n, i);         // sorted using heapSort()       
    }      
    heapSort(arr, n);
    // Time complexity for heapSort() = first in heapifying (O(n)) + second in sorting it will again heapify
        // for each element so(O(n log n)) = Overall Time Comlexity: O(n log n)
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // heap functions can be used by priority queue
    // Max-heap:
    // priority_queue<int> maxheap;
    // maxheap.push(1);
    // maxheap.push(2);
    // maxheap.push(5);
    // maxheap.push(3);
    // cout<<"Top element is "<<maxheap.top()<<endl;
    // Min-heap:
    // priority_queue<int, vector<int>, greater<int>> minheap;
    // minheap.push(1);
    // minheap.push(2);
    // minheap.push(5);
    // minheap.push(3);
    // cout<<"Top element is "<<minheap.top()<<endl;
    return 0;
}