/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
*/
//https://leetcode.com/problems/number-of-longest-increasing-subsequence/solutions/107293/java-c-simple-dp-solution-with-explanation/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0, maxlen = 0, n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1}); //dp[i] = {length, number of LIS end with nums[i]}
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first +1)dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first +1, dp[j].second};
                }
            }
            if(maxlen == dp[i].first)ans += dp[i].second;
            if(maxlen < dp[i].first){
                maxlen = dp[i].first;
                ans = dp[i].second;
            }
        }
        return ans;
    }
};