/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
 

Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.*/
//https://leetcode.com/problems/longest-arithmetic-subsequence/solutions/474884/c-dp-with-explanation/
//credit to HaelC
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int, int>> dp(nums.size());
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff)>0? dp[j][diff]+1: 2;
                maxi = max(maxi, dp[i][diff]);
            }
        }
        return maxi;
    }
};