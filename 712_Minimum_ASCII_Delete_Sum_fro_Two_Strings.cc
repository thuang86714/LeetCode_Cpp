/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.*/
/*
In this question we are given two strings , and asked to get the sum of ASCII values, to make string same,
RE-WORDING question : get the sum of all characters which do not form longest Common Subsequence.*/
class Solution {//SC O(mn), TC(mn)
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int j = 1; j <= n; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for(int i = 1; i <= m; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

//SC O(n)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<int> dp(n+1, 0);
        for(int j = 1; j <= n; j++){
            dp[j] = dp[j-1] + s2[j-1];
        }
        for(int i = 1; i <= m; i++){
            int temp1 = dp[0];
            dp[0] += s1[i-1];
            for(int j = 1; j <= n; j++){
                int temp2 = dp[j];
                dp[j] = s1[i-1] == s2[j-1]? temp1:min(dp[j]+s1[i-1], dp[j-1]+s2[j-1]);
                temp1 = temp2;
            }
        }
        return dp[n];
    }
};