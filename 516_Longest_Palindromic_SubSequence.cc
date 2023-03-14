/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(n == 1)return 1;
        vector<int> dp(n, 0), dp2(n, 0);
        for(int i = n-1; i >= 0; i--){//this is a bottom-up approach
            dp[i] = 1;
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]){
                    dp[j] = dp2[j-1]+2;//dp[i+1][j-1]
                }else{
                    dp[j] = max(dp2[j], dp[j-1]);
                }
            }
            swap(dp, dp2);
        }
        return dp2[n-1];

    }
};
//TC O(n^2), SC from O(n^2)-->O(n)
//https://leetcode.com/problems/longest-palindromic-subsequence/solutions/1468396/c-python-2-solutions-top-down-dp-bottom-up-dp-o-n-space-clean-concise/