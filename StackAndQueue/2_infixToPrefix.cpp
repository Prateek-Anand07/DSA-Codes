#include<bits/stdc++.h>
using namespace std;
string reverse(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        swap(s[i], s[n-1-i]);
    }
    return s;
}
string reversestrbrc(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        if(s[i]=='(')
            s[i] = ')';
        else if(s[i]==')')
            s[i] = '(';
        if(s[n-1-i]=='(')
            s[n-1-i] = ')';
        else if(s[n-1-i]==')')
            s[n-1-i] = '(';
        swap(s[i], s[n-1-i]);
    }
    if((n%2)!=0 && s[n/2]=='(')
        s[n/2] = ')';
    if((n%2)!=0 && s[n/2]==')')
        s[n/2] = '(';
    return s;
}
int priority(char c) {
    if(c == '^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}
string infixToPrefix(string s) {
    s = reversestrbrc(s);
    stack<char> st;
    string result = "";
    int n = s.length();
    for(int i=0; i<n; i++) {
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) // if operand then put it in string 
            result += c;
        else if(c == '(') // put it in stack
            st.push(c);
        else if(c == ')') { // till that you reach last or at c=='(' put characters in string and pop it out
            while(!st.empty() && st.top()!='(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // lastly pop'('
        }
        else {
            if(c == '^') {
                while(!st.empty() && priority(c)<=priority(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(c)<priority(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while(!st.empty()) { // after iteration put all operators in string top by top
        result += st.top();
        st.pop();
    }
    result = reverse(result);
    return result;
}
int main() {
    string s;
    cin>>s;
    s = infixToPrefix(s);
    cout<<s;
    return 0;
}