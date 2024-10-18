#include<iostream>
using namespace std;
int sum_n(int n) {
    if(n==0)
        return 0;
    else if(n==1) 
        return 1;
    else
        return n+sum_n(n-1);
}
int pow_n(int n, int p) {
    if(p==0)
        return 1;
    else if(p==1)
        return n;
    else
        return n*pow_n(n, p-1);
}
int factorial(int n) {
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}
int fibonacci(int n) {
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fibonacci(n-2)+fibonacci(n-1);
}
int main() {
    int n, p;
    cin>>n>>p;
    cout<<"Sum up to "<<n<<" terms is "<<sum_n(n)<<endl;
    cout<<n<<" raised to power of "<<p<<" is "<<pow_n(n, p)<<endl;
    cout<<n<<"! = "<<factorial(n)<<endl;
    cout<<"nth fibonacci number is "<<fibonacci(n);
    return 0;
}