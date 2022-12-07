/*
Given a string s, find the length of the longest substring without repeating characters.
Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/
//using sling window--> 2 ptrs
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;
        std::unordered_set<char> visited; //O(1) for fectching
        
        int maxStr = 0;

        for(int r=0 ;r < s.length() ;r++)
        {
            while(visited.count(s[r]) == 1) //if there's a duplicate key in the set
            {
                visited.erase(s[l]);
                l++;
            }
            visited.insert(s[r]);
            maxStr = max(maxStr,r-l+1);
        }
        return maxStr;
    }
};
