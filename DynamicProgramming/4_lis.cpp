// Longest increasing subsequence
#include <bits/stdc++.h>
using namespace std;

// Length of longest increasing sequence:

// Memoization:
// Time complexity: O(n^2)
// Space complexity: O(n^2)+O(n)
int lisLengthMemo(vector<int>& nums, int ind, int maxInd, vector<vector<int>>& dp) {
    if(ind == nums.size())
        return 0;
    if(dp[ind][maxInd+1] != -1)
        return dp[ind][maxInd+1];
    int take = 0;
    if(maxInd==-1 || nums[ind]> nums[maxInd])
        take = 1+lisLengthMemo(nums, ind+1, ind, dp);
    int skip = lisLengthMemo(nums, ind+1, maxInd, dp);
    return dp[ind][maxInd+1] = max(take, skip);
}

// Tabulation:
// Time complexity: O(n^2)
// Space complexity: O(n^2)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int ind=n-1; ind>=0; ind--) {
        for(int maxInd=ind-1; maxInd>=-1; maxInd--) {
            int take = 0;
            if(maxInd==-1 || nums[ind]>nums[maxInd]) {
                take = 1+dp[ind+1][ind+1];
            }
            int skip = dp[ind+1][maxInd+1];
            dp[ind][maxInd+1] = max(take, skip);
        }
    }
    return dp[0][0];
}

// Tabulation (space optimized):
// Time complexity: O(n^2)
// Space complexity: O(n)*2
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> ahead(n+1, 0), cur(n+1, 0);
    for(int ind=n-1; ind>=0; ind--) {
        for(int maxInd=ind-1; maxInd>=-1; maxInd--) {
            int take = 0;
            if(maxInd==-1 || nums[ind]>nums[maxInd]) {
                take = 1+ahead[ind+1];
            }
            int skip = ahead[maxInd+1];
            cur[maxInd+1] = max(take, skip);
        }
        ahead = cur;
    }
    return ahead[0];
}

// Tabulation (different method):
// Time complexity: O(n^2)
// Space complexity: O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int ind=0; ind<n; ind++) {
        for(int prev=0; prev<ind; prev++) {
            if(nums[ind] > nums[prev])
                dp[ind] = max(dp[ind], 1+dp[prev]);
        }
        ans = max(ans, dp[ind]);
    }
    return ans;
}

// Using binary search:
// Time complexity: O(nlogn)
// Space complexity: O(n)
int longestSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] > temp.back()) {
            temp.push_back(nums[i]);
            len++;
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len;
}

// Print longest increasing subsequence:
// Time complexity: O(n^2)+O(n)
// Space complexity: O(n)
vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
    vector<int> dp(n, 1), hash(n);
    int ans=1, lastIndex=0;
    hash[0] = 0;
    for(int ind=1; ind<n; ind++) {
        hash[ind] = ind;
        for(int prev=0; prev<ind; prev++) {
            if(nums[ind]>nums[prev] && 1+dp[prev]>dp[ind]) {
                dp[ind] = 1+dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind] > ans) {
            ans = dp[ind];
            lastIndex = ind;
        }
    }
    // returning ans will give length of lis
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
int main() {
    return 0;
}