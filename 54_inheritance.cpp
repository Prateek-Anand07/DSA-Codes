#include<iostream>
using namespace std;
class A {
    public:
    void funcA() {
        cout<<"Inheritance\n";
    }   
};
class B: public A {
    public:
    void funcB() {
        cout<<"Again\n";
    }
};
class C: public B {
    public:
};
class D: public A {
    public: 
};
int main() {
    C b;
    b.funcA();
    b.funcB();
    D d;
    d.funcA();
    return 0;
}