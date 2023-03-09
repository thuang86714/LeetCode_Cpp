/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1*/
//similar to Perfect Square
//DP+bottom up
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        vector<int> dp(amount+1, amount+1);//dont use INT_MAX, might cause overflow
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if((i - coins[j]) >= 0){
                    dp[i] = min(dp[i], 1+ dp[i -coins[j]]);
                }
            }
        }
        return dp[amount]==amount+1 ? -1: dp[amount];
        /*
        if(dp[amount]==amount+1){
            return -1;
        }else{
            return dp[amount];
        }*/
    }
};
//time complexity is O(amount*coins.size())
//space complexity is O(amount)