/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n: nums){
            sum += n;
        }
        if(sum%2 != 0)return false;
        int halfsum = sum/2;
        vector<bool> dp(halfsum+1, false);
        dp[0] = true;
        for(int n: nums){
            for(int j = halfsum; j >= n; j--){
                if(dp[j - n])dp[j] = true;
            }
        }
        return dp[halfsum];
    }
};
//TC O(Sum*N), SC O(Sum)
//https://leetcode.com/problems/partition-equal-subset-sum/solutions/1624939/c-python-5-simple-solutions-w-explanation-optimization-from-brute-force-to-dp-to-bitmask/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), halfsum = sum/2;
        if(sum%2 != 0)return false;
        bitset<10001> dp(1);//why 10001
        for(int n: nums){
            dp = dp | dp << n;
        }
        return dp[halfsum];
    }
};