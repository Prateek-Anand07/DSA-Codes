#include<bits/stdc++.h>
using namespace std;
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
string infixToPostfix(string s) {
    // Your code here
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
        else { // if there are operators 
            while(!st.empty() && (priority(c)<=priority(st.top()))) { /* if stack is not empty then put
                                                                        characters in string till it has 
                                                                        higher priority then top */
                result += st.top();
                st.pop();
            }
            st.push(c); // if stack is empty or at last put that operator in stack
        }
    }
    while(!st.empty()) { // after iteration put all operators in string top by top
        result += st.top();
        st.pop();
    }
    return result;
}
int main() {
    cout<<infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
    return 0;
}