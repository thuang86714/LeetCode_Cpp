/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3*/
//Turn it inot classic 0/1 knapsack problem
//https://leetcode.com/problems/target-sum/solutions/97340/c-python-short-dp-solution/
/*
We have nums=[1,2,3,4,5] and S=3 for example. There is a solution 1-2+3-4+5=3. 
After moving nums in negative to the right side, it becomes 1+3+5=3+2+4. 
Each side is half of sum(nums)+S. This means we can turn this into a knapsack problem 
with sacks=nums and target_sum=(sum(nums)+S)/2. In this example sacks=[1,2,3,4,5] 
and target_sum=9. [1,3,5] is one of the solutions.*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        if((sum + target)%2 ==1 || target > sum || target < -sum)return 0;
        int newTarget = (sum + target)/2;
        vector<int> dp(newTarget+1, 0);
        dp[0] =1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = newTarget; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newTarget];
    }
};