//https://leetcode.com/problems/permutation-in-string/solutions/1762469/c-sliding-window-optimized-well-explained/
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
C++ will allow us to compare two vectors without needing to write a comparison function, 
it will check the size first and then compare the contents of the vector in order. 
Since both vectors have the same order, we can exclude the "areVectorsEqual" function and 
it will also be accepted with the same O(26) as it will need to compare all 26 characters. 
This gives us the following code:*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> s1v (26, 0);
        for (auto c : s1) s1v[c - 'a']++;
        vector<int> s2v (26, 0);
        int l = 0, r = 0;
        while (r < s2.length()) {
            s2v[s2[r]-'a']++;
            if (r - l + 1 == s1.length()) 
                if (s1v == s2v) return true;
            if (r - l + 1 < s1.length()) r++;
            else {
                s2v[s2[l]-'a']--;
                l++;
                r++;
            }
        }
        return false;
    }
};