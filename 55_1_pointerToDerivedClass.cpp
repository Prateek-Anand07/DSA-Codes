#include<iostream>
using namespace std;
class BaseClass {
    public:
        int var_base;
        void display() {
            cout<<"Displaying base class variable var_base "<<var_base<<endl;
        }
};
class DerivedClass : public BaseClass {
    public:
        int var_derived;
        void display() {
            cout<<"Displaying base class variablr var_base "<<var_base<<endl;
            cout<<"Displaying derived class variable var_derived "<<var_derived<<endl;
        }
};
int main() {
    BaseClass *base_class_ptr;
    DerivedClass derived_class_obj;
    base_class_ptr = &derived_class_obj;
    base_class_ptr ->var_base = 34; 
    base_class_ptr ->display(); // points the display function of the class whose types pointer is defined
    DerivedClass *derived_class_ptr;
    derived_class_ptr = &derived_class_obj;
    derived_class_ptr ->var_base = 300;
    derived_class_ptr ->var_derived = 3;
    derived_class_ptr ->display();
    return 0;
}