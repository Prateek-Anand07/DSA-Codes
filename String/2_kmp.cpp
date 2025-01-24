#include <bits/stdc++.h>
using namespace std;
// Longest prefix suffix
// Given a string, find the length of the longest proper prefix which is also a proper suffix.
// Proper prefix: A proper prefix of a string is a prefix that is not equal to the string itself.
// Proper suffix: A proper suffix of a string is a suffix that is not equal to the string itself.
// Example: "abab" has a longest proper prefix which is also a proper suffix: "ab".
// Solving with brute force approach:
// 1. Find all the prefixes of the string.
// 2. Find all the suffixes of the string.
// 3. Find the longest common prefix and suffix.
// 4. Return the length of the longest common prefix and suffix.
// Code:
// Time complexity: O(n^2)
// Space complexity: O(1)
int longestPrefixSuffix(string s) {
    int n = s.length();
    int maxLen = 0;
    for(int len=1; len<n; len++) {
        if(s.substr(0, len) == s.substr(n-len, len)) // each time lenght is increasing by 1 so sum from 1 to n-1 is n(n-1)/2 thus give quadratic time complexity
            maxLen = len;
    }
    return maxLen;
}
// Solving with KMP algorithm: (KMP-> Knuth-Morris-Pratt)
// Time complexity: O(n)
// Space complexity: O(n)
int lpsKMP(string s) {
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
            if(pre == 0) {
                lps[suff] = 0;
                suff++;
            }
            else 
                pre = lps[pre-1]; // if characters are not equal then move the prefix pointer to the previous character of the prefix pointer (lps[pre-1] points to the character which is next to the longest prefix suffix till pre-1)
                // because the previous character of the prefix pointer is the last character of the longest proper prefix which is also a proper suffix of s[0..suff-1]
                // so we can check if the current character of the suffix pointer is equal to the previous character of the prefix pointer
                // if they are equal then we can increase the prefix pointer by 1
                // if they are not equal then we can move the prefix pointer to the previous character of the prefix pointer
        }
    }
    return lps[n-1]; 
}

// if want to print the longest prefix suffix string and if such string is not possible then print ""
// same function as above just reurning the lps vector whole
vector<int> lpsBuild(string s) {
    int n = s.length();
    vector<int> lps(n, 0); 
    int pre=0, suff=1; 
    while(suff < n) {
        if(s[pre] == s[suff]) { 
            lps[suff] =pre+1;
            pre++;
            suff++;
        }
        else { 
            if(pre == 0) {
                lps[suff] = 0;
                suff++;
            }
            else 
                pre = lps[pre-1]; 
        }
    }
    return lps; 
}
string longestPrefix(string s) {
    int n = s.length();
    vector<int> lps = lpsBuild(s);
    if(lps[n-1] == 0)
        return "";
    return s.substr(0, lps[n-1]);
}
int main() {
    return 0;
}