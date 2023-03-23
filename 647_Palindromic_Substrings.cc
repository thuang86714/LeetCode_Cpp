/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".*/
//https://leetcode.com/problems/palindromic-substrings/solutions/475745/c-dp-solution-recursive-memoization-tabulation/
class Solution {
public:
    int countSubstrings(string s) {
        //dp
        if(s.length() == 1)return 1;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));//dp[i][j] mark as the len of palin str between s[i] &&s[j]
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                ans += recur(dp, s, i, j);
            }  
        }
        return ans;
    }
private:
    int recur(vector<vector<int>> &dp, string s, int i, int j){
        if(i >= j)return 1;//the base case
        if(dp[i][j] > 0)return dp[i][j];
        return dp[i][j] = s[i] == s[j]? recur(dp, s, i+1, j-1): 0;
    }
};
//TC O(N^2), SC O(N^2);

/*a super solution, base on Nth triangle number: 
for exapmle:
a string aaaa
could be a x4
         aa x3
         aaa x2
         aaaa x1
so, for a string with identical char, whose len = n, 
the number of palindromic substing would be nth triangle number: n*(n+1)/2

*/
//https://leetcode.com/problems/palindromic-substrings/solutions/1129426/js-python-java-c-optimized-mathematical-solution-w-explanation/

class Solution {
public:
    int countSubstrings(string S) {
        int len = s.length(), ans = 0;
        for(int i = 0; i < len; i++){
            int j = i -1, k = i;
            while(k < len-1 && s[k] == s[k+1])k++;
            ans += (k -j)*(k - j +1)/2;
            i = k;
            k++;
            while(j >= 0 && k < len && s[k+1] == s[j--])ans++; 
            /*
            For integers, a 0 is falsy (meaning it evaluates to false in a conditional expression)
             and any non-zero value is truthy. With a bitwise NOT operator (~), 
             a 0 turns into a -1 and a -1 turns into a 0. 
             So while (~j) will continue until j = -1. 
             It's a convenient way to deal with iterating backwards through a 0-indexed array. 
             In this case, it's the functional equivalent to while (j >= 0), 
             but it's both shorter and faster.*/
        }
        return ans;
    }
};