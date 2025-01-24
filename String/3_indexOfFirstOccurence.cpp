#include <bits/stdc++.h>
using namespace std;
// Q. Index of first occurrence of a pattern in a text
// Given two strings text and pattern, find the first index where pattern exactly matches with any substring of text. 
// Return -1 if pattern doesn't exist as a substring in text.
// Example:
// Input:
// text = gffgfg
// pattern = gfg
// Output: 3
// Explanation:  Considering 0-based indexing, substring of text from 3rd to last index is gfg.


// Using KMP:
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
// Time complexity: O(n+m)
// Space complexity: O(m)
int findMatching(string text, string pat) {
    int n=text.length(), m=pat.length();
    if(n < m)
        return -1;
    vector<int> lps = lpsKMP(pat);
    int first=0, second=0;
    while(second<m && first<n) {
        if(text[first] == pat[second]) { 
            first++;
            second++;
        }
        else { // characters not matched
            if(second == 0) 
                first++;
            else
                second = lps[second-1]; // move the second pointer to the previous character of the second pointer
                // we want to decide without moving first pointer that from where we can start matching again
                // as we know text from 0 to first-1 is matched with pattern from 0 to second-1
                // so the longest prefix suffix of second is same as the longest prefix suffix of first
                // so the longest prefix of pattern will match with text till first-1
                // now we will start matching character at first and second pointer which is the next character of the longest prefix of pattern 
                // that's why we move the second pointer to the previous character of the second pointer
        }
    }
    if(second == m)
        return first-second; // first-second is the starting index of the pattern in the text because second which is 0 where the pattern starts matching with text while first indexing is universal, so subtracting will give the index where the pattern starts matching
    return -1; // if second is not reached to the end while first reached means text is exhausted but pattern is not found
}

int main() {
    return 0;
}