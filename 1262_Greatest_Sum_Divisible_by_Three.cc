/*
Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.*/
//https://leetcode.com/problems/greatest-sum-divisible-by-three/solutions/559999/come-here-if-you-can-t-seem-to-get-it-full-explanation-uncondensed-code/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        dp[0][1] = dp[0][2]= INT_MIN;
        for(int i = 1; i <= n; i++){
            if(nums[i-1]%3 == 0){
                dp[i][0] = max(dp[i-1][0], dp[i-1][0]+nums[i-1]);//Current remainder is 0, so we add to dp[i-1][0] to keep the remainder 0
                dp[i][1] = max(dp[i-1][1], dp[i-1][1]+nums[i-1]);//Current remainder is 0, so we add to dp[i-1][1] to keep the remainder 1
                dp[i][2] = max(dp[i-1][2], dp[i-1][2]+nums[i-1]);//Current remainder is 0, so we add to dp[i-1][2] to keep the remainder 2
            }else if(nums[i-1]%3 == 1){
                dp[i][0] = max(dp[i-1][0], dp[i-1][2]+nums[i-1]);//Current remainder is 1, so we add to dp[i-1][2] to keep the remainder 0
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]+nums[i-1]);//Current remainder is 1, so we add to dp[i-1][0] to keep the remainder 1
                dp[i][2] = max(dp[i-1][2], dp[i-1][1]+nums[i-1]);//Current remainder is 1, so we add to dp[i-1][1] to keep the remainder 2
            }else if(nums[i-1]%3 == 2){
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+nums[i-1]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][2]+nums[i-1]);
                dp[i][2] = max(dp[i-1][2], dp[i-1][0]+nums[i-1]);
            }
        }
        return dp[n][0];
    }
};