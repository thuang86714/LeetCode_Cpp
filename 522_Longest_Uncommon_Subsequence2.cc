/*
Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
 

Example 1:

Input: strs = ["aba","cdc","eae"]
Output: 3*/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maximum = -1;
        int n = strs.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(isASubseqOfB(strs[i], strs[j]) && i != j){
                    count++;
                    break;
                }
            }
            if(count == 0)maximum = max(maximum, int(strs[i].size()));
        }
        return maximum;
    }
private:
    bool isASubseqOfB(const string& a, const string& b){
        int i = 0, j = 0;
        while(i < a.length() && j < b.length()){
            if(a[i] == b[j])i++;
            j++;
        }
        return i == a.length();
    }
};
//https://leetcode.com/problems/longest-uncommon-subsequence-ii/solutions/235912/c-solution-beats-100-with-the-detail-explanation/