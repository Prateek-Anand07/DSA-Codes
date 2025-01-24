#include <bits/stdc++.h>
using namespace std;
// Q. Count all palindromic subsequence in a string
// Given a string s, you have to find the number of palindromic subsequences (need not necessarily be distinct) present in the string s. 

// Example:
// Input: s = "aab"
// Output: 4
// Explanation: The palindromic subsequences are {"a", "a", "b", "aa"}

// Time complexity: O(n^2)
// Space complexity: O(n^2)
int countPS(string &s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    for(int len=2; len<=n; len++) {
        for(int i=0; i<=n-len; i++) {
            int j = i+len-1;
            if(s[i] == s[j])
                dp[i][j] = 1+dp[i][j-1]+dp[i+1][j]; // not subtracted beacuse it will once counted as single char palindrome then again it will attach between two equal chars and make palindrome
            else
                dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
        }
    }
    return dp[0][n-1];
}
int main() {
    return 0;
}