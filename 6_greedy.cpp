#include <bits/stdc++.h>
using namespace std;
// Q. Assign Cookies
//  Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// Code:
int findContentChildren(vector<int>& g, vector<int>& s) {
    int n=g.size(), m=s.size();
    sort(g.begin(), g.end()); // first sort both, (n log n)
    sort(s.begin(), s.end()); // (m log m)
    int l=0, r=0; // take two pointers and iterate and we will try to start with minimum values which is greedy approach here
    while(l<n && r<m) { // (O(min(n, m)))
        if(g[l] <= s[r]) {// if condition is satisfied we will give that cooky to child and increase the pointer of greediness, i.e, count of child
            l++; // if condition not satisfied pointer not increases as it is checked with another cooky
        }
         r++; // cookies size pointer is increase always because it is given to that child or if not then it can't be given to any next child as next ones will have more greediness then that
    }
    return l; // position will give the count
}
// Time complexity = O(n log n)+O(m log m)+O(min(n, m)) ~ O(n log n)
// Space complexity = O(1)
int main() {
    return 0;
}