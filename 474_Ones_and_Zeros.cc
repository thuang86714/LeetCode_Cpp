/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:*/
//https://leetcode.com/problems/ones-and-zeroes/solutions/1138589/short-easy-w-explanation-o-l-m-n-dp-solution-6-lines-similar-to-knapsack/
//credit to archit91
//Time Complexity : O(L*m*n), where L is the length of strs
//Space Complexity : O(m*n)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size() == 1)return strs.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (auto str: strs){
            int zeros = count(str.begin(), str.end(), '0');
            int ones = str.length() - zeros;

            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones ; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones]+1);
                }
            }
        }
        return dp[m][n];

    }
};