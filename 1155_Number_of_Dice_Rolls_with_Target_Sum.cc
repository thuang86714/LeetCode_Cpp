/*
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.*/
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/solutions/355940/c-coin-change-2/
class Solution {
public:
    int dp[31][1001] = {};
    int mod = 1000000000+7;
    int numRollsToTarget(int d, int f, int target, int res = 0) {
        
        if (d == 0 || target <= 0) return d == target;//d == target is the shorthand for d == 0 && target == 0.
        if (dp[d][target]) return dp[d][target] - 1;
        for (auto i = 1; i <= f; ++i)
        res = (res + numRollsToTarget(d - 1, f, target - i)) %mod ; 
        dp[d][target] = res + 1;
        return res;
}
};