#include <bits/stdc++.h>
using namespace std;

// To check target sum can be achieved or not from given array where array can have negative elements also target can be negative

// Memoization approach:
// Map is used to store negative value of target
// Time complexity: O(N*2*totalSum)
// Space complexity: O(N*2*totalSum)+O(N)
bool helper(vector<int>& arr, int target, int ind, map<pair<int, int>, bool>& mp, int totalSum) {
  if(target == 0)
    return true;
  if(ind == 0) 
    return (arr[0] == target);
  if(mp.find({ind, target}) != mp.end())
    return mp[{ind, target}];
  bool notTake = helper(arr, target, ind-1, mp, totalSum);
  bool take = false;
  if(target-arr[ind]>=-totalSum && target-arr[ind]<=totalSum)
    take = helper(arr, target-arr[ind], ind-1, mp, totalSum);
  return mp[{ind, target}] = notTake || take;
}

// Tabulation approach with space optimization:
// Vector is used with negative index adjusted using offset value
// Time complexity: O(N*2*totalSum)
// Space complexity: O(2*totalSum)
bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    int totalSum = 0;

    // Calculate total absolute sum for offset
    for (int num : arr)
        totalSum += abs(num);

    int offset = totalSum; // Offset to handle negative sums
    int dpCols = 2 * totalSum + 1; // Size of dp table columns
        
    // Initialize DP table
    vector<bool> prev(dpCols, false), cur(dpCols, false);

    // Base case: dp[i][offset] = true (sum = 0 is always possible)
    prev[offset] = true;
    cur[offset] = true;

    // Base case for first element
    if (arr[0] + offset >= 0 && arr[0] + offset < dpCols) 
        prev[arr[0] + offset] = true;

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < dpCols; j++) {
            if(j == offset) continue;
            bool notTake = prev[j]; // Not taking the current element
            bool take = false; 
            int sumIndex = j - arr[i]; // Adjust for offset
                
            // Check if taking the element is valid
            if (sumIndex >= 0 && sumIndex < dpCols) 
                take = prev[sumIndex];

            cur[j] = notTake || take;
        }
        prev = cur;
    }

    // Return the result for target + offset
    int targetIndex = target + offset;
    return targetIndex >= 0 && targetIndex < dpCols ? prev[targetIndex] : false;
}

// Number of subsets with sum equal to target:
// Time complexity: O(N*2*totalSum)
// Space complexity: O(2*totalSum)
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    int totalSum = 0;
    
    // Calculate total absolute sum for offset
    for (int num : arr)
        totalSum += abs(num);
    
    int offset = totalSum; // Offset to handle negative sums
    int dpCols = 2 * totalSum + 1; // Size of dp table columns
    vector<int> prev(dpCols, 0), cur(dpCols, 0);
    prev[offset] = cur[offset] = 1;
    if(arr[0] == 0)
        prev[offset] = 2;
    if((arr[0]+offset>=0 && arr[0]+offset<dpCols) && arr[0]!=0)
        prev[arr[0]+offset] = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<dpCols; j++) {
            int notTake = prev[j];
            int take = 0;
            int sumInd = j-arr[i];
            if(sumInd>=0 && sumInd<dpCols)
                take = prev[sumInd];
            cur[j] = notTake+take;
        }
        prev = cur;
    }
    int targetInd = target+offset;
    return prev[targetInd];
}
int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    int totalSum = 0;
    for (int num : arr)
        totalSum += abs(num);
    if(isSubsetSum(arr, target))
        cout<<"Target sum can be achieved from given array"<<endl;
    else
        cout<<"Target sum can't be achieved from given array"<<endl;
    return 0;
}