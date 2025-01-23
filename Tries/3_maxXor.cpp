#include <bits/stdc++.h>
using namespace std;
// Q. Given an array of numbers and a number x, find max value of (arr[i]^x) for all i.
// The idea is to use a trie data structure to store the binary representation of the numbers.
// We will insert the binary representation of the numbers in the trie.
// For each number, we will find the number that will give the maximum XOR with it.
// We will traverse the trie from the most significant bit to the least significant bit.
// If the current bit is 0, we will try to find a 1 in the trie, and vice versa.
// If we find a bit that is different from the current bit, we will take that bit.
// If we don't find a bit that is different from the current bit, we will take the same bit.
// This will give us the maximum XOR value.
struct Node {
    Node* links[2];
    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};
class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insert(int num) {
            Node* node = root;
            for(int i=31; i>=0; i--) {
                int bit = (num>>i)&1;
                if(!node->containsKey(bit))
                    node->put(bit, new Node());
                node = node->get(bit);
            }
        }
        int getMaxXor(int num) {
            Node* node = root;
            int maxXor = 0;
            for(int i=31; i>=0; i--) {
                int bit = (num>>i)&1;
                if(node->containsKey(1-bit)) {
                    maxXor = maxXor | (1<<i);
                    node = node->get(1-bit);
                } 
                else    
                    node = node->get(bit);
            }
            return maxXor;
        }
};
int main() {
    int n, x;
    cout<<"Enter the number of elements: ";
    cin>>n; 
    cout<<"Enter the number to find max XOR with: ";
    cin>>x;
    vector<int> arr(n);
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    Trie trie;
    for(int num : arr) {
        trie.insert(num);
    }
    int maxXor = trie.getMaxXor(x);
    cout<<"Max XOR value: "<<maxXor<<endl;
    // Now an array is given and find maximum Xor of two elements in the array.
    maxXor = 0;
    for(auto ele: arr) {
        maxXor = max(maxXor, trie.getMaxXor(ele));
    }
    cout<<"Max XOR value of two elements in the array: "<<maxXor<<endl;
    return 0;
}