/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3*/
//https://leetcode.com/problems/longest-common-subsequence/solutions/348884/c-with-picture-o-nm/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001] = {};
        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                dp[i+1][j+1] = text1[i] == text2[j]? dp[i][j]+1: max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

class Solution{//space optimized verion
    int longestCommonSubsequence(string &a, string &b) {
    short m[1001][1001] = {};
    for (auto i = 0; i < a.size(); ++i)
        for (auto j = 0; j < b.size(); ++j)
            m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    return m[a.size()][b.size()];
}
};