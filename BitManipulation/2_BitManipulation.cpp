#include<bits/stdc++.h>
using namespace std;
string convert2binary(int n) { // Time Complexity = Space Complexity = O(log n)
    string res = "";
    while(n!=0) {
        if(n%2==1)
            res += '1';
        else
            res += '0';
        n/=2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int getBit(int n, int pos) {
    return ((n & (1 << pos))!=0);
}
int setBit(int n, int pos) {
    return (n | (1<<pos));
}
int clearBit(int n, int pos) {
    return (n & (~(1<<pos)));
}
int updateBit(int n, int pos) {
    int x = n&(~(1<<pos));
    return x|(1<<pos);
}
void swap(int *a, int *b) {
    *a = *a^*b; 
    *b = *a^*b; // XOR of same numbers is zero
    *a = *a^*b;
}
int toogleBit(int n, int pos) { // change the bit at that pos
    return n^(1<<pos);
}
int removeLastSetBit(int n) {
    return n&(n-1);
}
int main() {
    cout<<(removeLastSetBit(16));
    return 0;
}