#include <bits/stdc++.h>
using namespace std;
// Shortest palindrome
// Q. You are given a string s. You can convert s to a palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.

// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"

// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

// Time complexity: O(n^2)
// Space complexity: O(n)
string shortestPalindrome(string s) {
    int n = s.length();
    if(n == 0)
        return "";
    string rev = s;
    reverse(rev.begin(), rev.end()); 
    for(int len=n; len>=1; len--) {
        if(s.substr(0, len) == rev.substr(n-len)) 
        // if(!memcmp(s.c_str(), rev.c_str()+n-len, len)) // memcmp is used to compare memory blocks
                                                        // memcmp(s.c_str(), rev.c_str()+n-len, len) returns 0 if the memory blocks are equal
                                                        // this avoids the extra internal space to create substring using substr() function
            return rev.substr(0, n-len)+s;
    }
    return "";
}

vector<int> lpsKMP(string s) {
    int n = s.length();
    vector<int> lps(n, 0); // lps[i] stores the length of the longest proper prefix which is also a proper suffix of s[0..i]
    int pre=0, suff=1; 
    while(suff < n) {
        if(s[pre] == s[suff]) { // if characters are equal then increase the prefix and suffix pointer
            lps[suff] =pre+1;
            pre++;
            suff++;
        }
        else { // not equal
            if(pre == 0) 
                suff++;
            else 
                pre = lps[pre-1]; // if characters are not equal then move the prefix pointer to the previous character of the prefix pointer
        }
    }
    return lps; 
}
// Optimized approach using KMP algorithm:
// Time complexity: O(n)
// Space complexity: O(n)
string shortestPalindromeOpt(string s) { // s = "aacecaaa"
    int n = s.length();
    if(n == 0)
        return "";
    string rev = s;
    reverse(rev.begin(), rev.end());
    vector<int> lps = lpsKMP(s+"&"+rev); // "aacecaaa&aaacecaa" 
    // lps = {0, 1, 0, 0, 0, 1, 2, 2, 0, 1, 2, 2, 3, 4, 5, 6, 7} here 7 says that the longest prefix suffix of s+"&"+rev is of length 7 which is aacecaa which is a longest palindrome in the string s from starting index now the left over part is distrubing to make it a palindrome 
    // so we can take that part and add s to it and return 
    // also we have to take that part in reverse order from last
    // so we take rev from 0th index and length = total string length - length of longest palindrome (lps[2*n])
    return rev.substr(0, n-lps[2*n])+s; 
}
int main() {
    string s = "aacecaaa&aaacecaa";
    vector<int> lps = lpsKMP(s);
    for(int i=0; i<lps.size(); i++)
        cout<<lps[i]<<" ";
    return 0;
}