/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //it's a DP problem, and this solution is space-optimal
        int buy = (*max_element(prices.begin(), prices.end())+1)*-1;//one should be very careful with INT_MIN, sice it ould cause overflow easily. Otherwise, the initial value could be  (*max_element(prices.begin(), prices.end())+1)*-1;
        int sell = 0;
        int prev_sell = 0, prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);//prev_sell is rest[i-1]
            prev_sell = sell;
            sell = max(prev_buy + price, sell);//prev_buy is buy[i-1]
        }
        return sell;
    }
};
//space complexity O(1)
//time complexity O(prices.size())
/*
buy[i]  = max(rest[i-1]-price, buy[i-1]) 
sell[i] = max(buy[i-1]+price, sell[i-1])
rest[i] = max(sell[i-1], buy[i-1], rest[i-1])
One tricky point is how do you make sure you sell before you buy, since from the equations it seems that [buy, rest, buy] is entirely possible.

Well, the answer lies within the fact that buy[i] <= rest[i] which means rest[i] = max(sell[i-1], rest[i-1]). That made sure [buy, rest, buy] is never occurred.

A further observation is that and rest[i] <= sell[i] is also true therefore

rest[i] = sell[i-1]*/