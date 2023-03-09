/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.*/
//https://leetcode.com/problems/combination-sum-iv/solutions/85120/c-template-for-all-combination-problem-set/
//credit to fight.for.dream
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //dp[i] : record the possible combination count to sum to target value of i
        vector<unsigned int> dp(target + 1);
        
        dp[0] = 1;
        
        sort (nums.begin(), nums.end());
        
        for (int i = 1; i <= target; i++) 
        {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};