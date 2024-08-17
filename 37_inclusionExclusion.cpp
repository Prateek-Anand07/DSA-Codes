#include<iostream>
using namespace std;
int divisibleNo(int n, int a, int b) {
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    return c1+c2-c3;
}
int gcd(int a, int b) {
    while(b!=0) {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}
int main() {
    // cout<<divisibleNo(40, 5, 7);
    cout<<gcd(24, 36);
    return 0;
}