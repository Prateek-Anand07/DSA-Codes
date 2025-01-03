#include <bits/stdc++.h>
using namespace std;
// Memoization technique (also called top-down approach)
// Time complexity: O(N)
// Space complexity: O(2N) (recursion stack space + dp array)
int fib(int n, vector<int>& dp) {
    if(n <= 1) 
        return n;
    if(dp[n] != -1)
        return dp[n]; // if already solved then return directly
    return dp[n]=fib(n-1, dp)+fib(n-2, dp); // memoization
}
// Tabulation technique (also called bottom-up approach)
// Time complexity: O(N)
// Space complexity: O(N) (better then memorization as no recursion stack space)
int fibTab(int n, vector<int>& dp) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) 
        dp[i] = dp[i-1]+dp[i-2];
    return dp[n];
}
// Space optimization in Tabulation
// Time complexity: O(N)
// Space complexity: O(1)
int fibTabOptimized(int n) {
    if(n <= 1)
        return n;
    int prev2=0, prev=1;
    int curr;
    for(int i=2; i<=n; i++) {
        curr = prev2+prev;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<fibTabOptimized(n);
    return 0;
}