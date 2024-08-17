#include<iostream>
#include<string>
using namespace std;
// To reverse a string
void reverse(string str) {
    if(str.length()==0)
        return;
    string restString = str.substr(1);
    reverse(restString);
    cout<<str[0];
}
void replacePi(string s) {
    if(s.length()==0) {
        return;
    }
    if(s[0]=='p' && s[1]=='i') {
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else {
        cout<<s[0];
        replacePi(s.substr(1));
    }
}
// Tower of Hanoi
void toh(int n, char src, char dest, char helper) {
    if(n==0) // Base case
        return;
    toh(n-1, src, helper, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    toh(n-1, helper, dest, src);
}
// To remove duplicates
string removeDup(string s) {
    if(s.length()==0)
        return "";
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if(ch==ans[0])
        return ans;
    return ch+ans;
}
// To move all x at end
string moveAll(string s) {
    if(s.length()==0)
        return "";
    char ch = s[0];
    string ans = moveAll(s.substr(1));
    if(ch=='x')
        return ans+ch;
    return ch+ans;
}
// Print all substrings of a string
void substrings(string s, string ans) {
    if(s.length()==0) {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    substrings(ros, ans);
    substrings(ros, ans+ch); 
}
// Print all substring with their ASCII value
void substringsASCII(string s, string ans) {
    if(s.length()==0) {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    substringsASCII(ros, ans);
    substringsASCII(ros, ans+ch); 
    substringsASCII(ros, ans+to_string(code));
}
void keypad(string s, string ans) {
    string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(s.length()==0) {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string code = keypadArr[ch-'0'];
    string ros = s.substr(1);
    for(int i=0; i<code.length(); i++) {
        keypad(ros, ans+code[i]);
    }
}
int main() {
    // string str = "Binod";
    // reverse(str);
    // string str = "pippppiiiipiiii";
    // replacePi(str);
    // toh(3, 'A', 'C', 'B');
    // cout<<removeDup("aaaaddddeeeeffff");
    // cout<<moveAll("xxtysxly");
    // substrings("ABC", "");
    // substringsASCII("ABC", "");
    keypad("23", "");
    return 0;
}