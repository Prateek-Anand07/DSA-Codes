#include <bits/stdc++.h>
# define ll long long
# define mod 1000000007
# define radix1 26
# define radix2 27
# define mod1 1000000007
# define mod2 1000000033
using namespace std;
// Rabin-Karp algorithm

// Q. Index of first occurrence of a pattern in a text
// Given two strings text and pattern, find the first index where pattern exactly matches with any substring of text. 
// Return -1 if pattern doesn't exist as a substring in text.
// Example:
// Input:
// text = gffgfg
// pattern = gfg
// Output: 3
// Explanation:  Considering 0-based indexing, substring of text from 3rd to last index is gfg.


ll hashValue(string s, ll radix, int m) {
    ll ans=0, factor=1;
    for(int i=m-1; i>=0; i--) {
        ans = (ans+(s[i]-'a')*factor)%mod;
        factor = (factor*radix)%mod;
    }
    return ans%mod;
}
// Time complexity: O(n*m) due to doing mod everywhere which may give spurious hits but in general it is O(n+m)
// Space complexity: O(1)
int findMatching(string text, string pat) {
    int n=text.length(), m=pat.length();
    if(n < m)
        return -1;
    ll radix=26, max_weight=1;
    for(int i=1; i<=m; i++) {
        max_weight = (max_weight*radix)%mod;
    }
    ll hashPat = hashValue(pat, radix, m);
    ll hashText = 0;
    for(int i=0; i<=n-m; i++) {
        if(i == 0)
            hashText = hashValue(text, radix, m);
        else 
            hashText = ((hashText*radix)%mod - ((text[i-1]-'a')*max_weight)%mod + (text[i+m-1]-'a'))%mod;
        if(hashPat == hashText) {
            for(int j=0; j<m; j++) {
                if(pat[j] != text[i+j])
                    break;
                if(j == m-1)
                    return i;
            }
        }
    }
    return -1;
}

// Optimized approach:

pair<ll, ll> twoHashValue(string s, int m) {
    ll ans1=0, ans2=0, factor1=1, factor2=1;
    for(int i=m-1; i>=0; i--) {
        ans1 = (ans1+(s[i]-'a')*factor1)%mod1;
        ans2 = (ans2+(s[i]-'a')*factor2)%mod2;
        factor1 = (factor1*radix1)%mod1;
        factor2 = (factor2*radix2)%mod2;
    }
    return {ans1%mod1, ans2%mod2};
}
// Time complexity: O(n+m)
// Space complexity: O(1)
// taking two hash values with the taken radix and mod will decrease the probability of spurious hits to 10^-10 so it is very low chance of having complexity O(n*m)
int findMatchingOpt(string text, string pat) {
    int n=text.length(), m=pat.length();
    if(n < m)
        return -1;
    ll max_weight1=1, max_weight2=1;
    for(int i=1; i<=m; i++) {
        max_weight1 = (max_weight1*radix1)%mod1;
        max_weight2 = (max_weight2*radix2)%mod2;
    }
    pair<ll, ll> hashPat = twoHashValue(pat, m);
    pair<ll, ll> hashText = {0, 0};
    for(int i=0; i<=n-m; i++) {
        if(i == 0)
            hashText = twoHashValue(text, m);
        else {
            hashText.first = ((hashText.first*radix1)%mod1 - ((text[i-1]-'a')*max_weight1)%mod1 + (text[i+m-1]-'a'))%mod1;
            hashText.second = ((hashText.second*radix2)%mod2 - ((text[i-1]-'a')*max_weight2)%mod2 + (text[i+m-1]-'a'))%mod2;
        }
        if(hashPat.first==hashText.first && hashPat.second==hashText.second) {
            for(int j=0; j<m; j++) {
                if(pat[j] != text[i+j])
                    break;
                if(j == m-1)
                    return i;
            }
        }
    }
    return -1;
}
int main() {
    return 0;
}