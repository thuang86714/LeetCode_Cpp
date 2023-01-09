/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into
 a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.*/
//it's a DP problem;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends     there. The optimization is to look from current position i back and only substring and do dictionary look up in case the preceding position j with dp[j] == true is found
        */
        vector<bool> dp(s.size()+1, false);
        dp[0] = true; //as the base case, Because we have to take the base case (i.e a string of size 0 could always be segmented). a top-down approach
        
        for (int i = 1; i <=s.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if (dp[j]){
                    string word = s.substr(j, i-j);
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                        dp[i]= true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};