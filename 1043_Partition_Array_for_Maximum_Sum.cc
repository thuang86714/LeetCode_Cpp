/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]*/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i = 1; i <= n; ++i){
            int curMax = 0, curSum = 0;
            for(int j = 1; j <= k&& (i-j)>=0; ++j){
                curMax = max(curMax, arr[i-j]);
                curSum = max(curSum, dp[i-j]+curMax*j);
            }
            dp[i] = curSum;
        }
        return dp[n];
    }
};