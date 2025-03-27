#include <bits/stdc++.h>
using namespace std;
// An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

// Boyer Moore majority voting algorithm:
// Time complexity: O(n)
// Space complexity: O(1)
int dominant(vector<int> nums) {
    int n = nums.size();
    int x=nums[0], cnt=0;
    for(auto it: nums) {
        if(it == x) 
            cnt++;
        else
            cnt--;
        if(cnt == 0) {
            x = it;
            cnt = 1;
        }
    }
    return x;
}
int main() {
    return 0;
}