#include<iostream>
using namespace std;
int main() {
    // Q1 to find maximum of three numbers
    int a, b, c;
    cout<<"enter three digits:\n";
    cin>>a>>b>>c;
    // if(a>b) {
    //     if(a>c)
    //     cout<<"a is maximum";
    //     else 
    //     cout<<"c is maximum";
    // }
    // else {
    //     if(b>c) 
    //     cout<<"b is maximum";
    //     else 
    //     cout<<"c is maximum";
    // }
    // Q2 to check a number is odd or even
    if(a%2==0)
    cout<<a<<" is even";
    else 
    cout<<a<<" is not even";
    return 0;
}