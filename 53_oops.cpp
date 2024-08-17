#include<iostream>
using namespace std;
float area(int r) {
    return 3.14*r*r;
}
float area(int l, int b) {
    return l*b;
}
class student {
    string name;
    public:
    int age;
    bool gender;
    student() {
        cout<<"Default constructor"<<endl;
    }
    student(string s, int a, bool g) {
        cout<<"Parameterised constructor"<<endl;
        name = s;
        age = a;
        gender = g;
    }
    student(student &a) {
        cout<<"Copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~student() {
        cout<<"Destructor called"<<endl;
    }
    bool operator == (student &a) {
        if(name == a.name && age == a.age && gender == a.gender) {
            return true;
        }
        else
            return false;
    }
    void setName(string s) {
        name = s;
    }
    string getName() {
        return name;
    }
    void printInfo() {
        cout<<"Name = "<<name<<endl;
        cout<<"Age = "<<age<<endl;
        cout<<"Gender = "<<gender<<endl;
    }
};
int main() {
    // student arr[1];
    // student a;
    // a.name = "Prateek";
    // cout<<a.name<<endl;
    // a.age = 19;
    // a.gender = 1;
    // cout<<a.age<<endl;
    // cout<<a.gender<<endl;
    // for(int i=0; i<1; i++) {
    //     string s;
    //     cout<<"Name = ";
    //     getline(cin, s);
    //     arr[i].setName(s);
    //     // cin>>arr[i].name;
    //     cout<<"Age = ";
    //     cin>>arr[i].age;
    //     cout<<"Gender = ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0; i<1; i++) {
    //     arr[i].printInfo();
    // }
    // student a;
    student b("Prateek Anand", 18, 1);
    student c(b);
    // student c = b; // or above to copy
    // c.printInfo();
    // string s;
    // cin>>s;
    // a.setName(s);
    // cout<<a.getName();
    student a;
    if (b==a) 
        cout<<"same\n";
    else
        cout<<"not same\n";
    cout<<"Circle area"<<area(1)<<endl;
    cout<<"Rectangle area"<<area(3,2)<<endl;
    return 0;
}