#include<bits/stdc++.h>
using namespace std;
string preToInfix(string pre_exp) {
    int i = pre_exp.length()-1;
    stack<string> st;
    while(i>=0) {
        if((pre_exp[i]>='a' && pre_exp[i]<='z') || (pre_exp[i]>='A' && pre_exp[i]<='Z') || 
        (pre_exp[i]>='0' && pre_exp[i]<='9')) {
            string ch(1, pre_exp[i]);
            st.push(ch);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("("+t1+pre_exp[i]+t2+")");
        }
        i--;
    }
    return st.top();
}
int main() {
    string s;
    cin>>s;
    cout<<preToInfix(s);
    return 0;
}