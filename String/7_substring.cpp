#include <iostream>
#include <string>

using namespace std;

// Time complexity: O(N^2)
void printSubstring(string s, int n, int start, int ind, string cur) { 
    if(start == n)
        return;
    if(cur.length())
        cout<<cur<<endl;
    if(ind < n)
        printSubstring(s, n, start, ind+1, cur+s[ind]);
    else    
        printSubstring(s, n, start+1, start+1, "");
}


int main() {
    string s = "abc";
    int n = s.length();
    // Time complexity: O(N^2)
    // for(int i=0; i<n; i++) {
    //     string temp = "";
    //     for(int j=i; j<n; j++) {
    //         temp += s[j];
    //         cout<<temp<<endl;
    //     }
    // }
    printSubstring(s, n, 0, 0, "");
    return 0;
}
