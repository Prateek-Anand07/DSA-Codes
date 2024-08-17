#include<bits/stdc++.h>
using namespace std;
string postToPre(string post_exp) {
    stack<string> st;
    int i=0;
    while(i<post_exp.length()) {
        if((post_exp[i]>='a' && post_exp[i]<='z') || (post_exp[i]>='A' && 
        post_exp[i]<='Z') || (post_exp[i]>='0' && post_exp[i]<='9')) {
            string ch(1, post_exp[i]);
            st.push(ch);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(post_exp[i]+t2+t1);
        }
        i++;
    }
    return st.top();
}
int main() {
    string s;
    cin>>s;
    cout<<postToPre(s);
    return 0;
}