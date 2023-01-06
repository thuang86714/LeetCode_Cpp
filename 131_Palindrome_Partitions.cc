/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]*/
//credit to ezspeed
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;
        if(s.empty())return result;
        dfs(s,result, temp, 0);
        return result;
    }
private:
    bool isPalindrome(const string& s, int begin, int end){
        while(begin <= end){
            if (s[begin++] != s[end--])return false;
        }
        return true;
    }

    void dfs(string& s, vector<vector<string>>& result, vector<string>& temp, int index){
        if (index == s.size()){//base case
            result.push_back(temp);
            return;
        }
        for (int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i -index +1));
                dfs(s, result, temp, i+1);
                temp.pop_back();
            }
        }
        
    }
};