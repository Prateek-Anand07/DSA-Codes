#include <bits/stdc++.h>
using namespace std;
// Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.
// Example:
// Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
// Output:11
// Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.

// Recursive approach:
// Time complexity: O(3^N)
// Space complexity: O(N)
int maximumPoints(vector<vector<int>>& arr, int day, int act) { 
    if(day == 0) {
        int maxi = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i != act) {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for(int i=0; i<3; i++) {
        if(i != act) {
            maxi = max(maxi, arr[day][i]+maximumPoints(arr, day-1, i));
        }
    }
    return maxi;
}

// Memoization:
// Time complexity: O(N*4*3)
// Space complexity: O(N*4)+O(N)
int maximumPointsMemo(vector<vector<int>>& arr, int day, int act, vector<vector<int>>& dp) { 
    if(day == 0) {
        int maxi = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i != act) {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][act] != -1)
        return dp[day][act];
    int maxi = INT_MIN;
    for(int i=0; i<3; i++) {
        if(i != act) {
            maxi = max(maxi, arr[day][i]+maximumPointsMemo(arr, day-1, i, dp));
        }
    }
    return dp[day][act] = maxi;
}

// Tabulation technique:
// Time complexity: O(N*4*3)
// Space complexity: O(N*4)
int maximumPointsTab(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
    for(int day=1; day<n; day++) {
        for(int i=0; i<4; i++) {
            dp[day][i] = 0;
            for(int j=0; j<3; j++) {
                if(j != i) {
                    dp[day][i] = max(dp[day][i], arr[day][j]+dp[day-1][j]);
                }
            }
        }
    }
    return dp[n-1][3];
}

// Space Optimization:
// Time complexity: O(N*4*3)
// Space complexity: O(4)
int maximumPointsOptim(vector<vector<int>>& arr, int n) {
    vector<int> dp(4, -1);
    dp[0] = max(arr[0][1], arr[0][2]);
    dp[1] = max(arr[0][0], arr[0][2]);
    dp[2] = max(arr[0][0], arr[0][1]);
    dp[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
    for(int day=1; day<n; day++) {
        vector<int> temp(4);
        for(int i=0; i<4; i++) {
            temp[i] = 0;
            for(int j=0; j<3; j++) {
                if(j != i) {
                    temp[i] = max(temp[i], arr[day][j]+dp[j]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}
int main() {
    int days;
    cin>>days;
    vector<vector<int>> arr(days);
    for(int i=0; i<days; i++) {
        for(int j=0; j<3; j++) {
            int x;
            cin>>x;
            arr[i].push_back(x);
        }
    }
    vector<vector<int>> dp(days, vector<int>(4, -1));
    cout<<maximumPointsMemo(arr, days-1, 3, dp);
    return 0;
}