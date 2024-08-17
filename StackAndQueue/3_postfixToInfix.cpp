#include<bits/stdc++.h>
using namespace std;
string postToInfix(string exp) {
    stack<string> st;
    int i = 0;
    while(i<exp.length()) {
        if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9')) {
            string ch(1, exp[i]);
            st.push(ch);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("(" + t2 + exp[i] + t1 + ")");
        }
        i++;
    }
    return st.top();
}
int main() {
    string s;
    cin>>s;
    cout<<postToInfix(s);
    return 0;
}