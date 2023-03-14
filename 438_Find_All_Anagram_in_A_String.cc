/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //sliding window, size of window == plength
        int p_leng = p.length();
        int s_leng = s.length();
        if(s_leng < p_leng)return {};
        vector<int> result;
        vector<int> freq(26, 0);
        vector<int> window(26, 0);
        //first window
        for(int i = 0; i < p_leng; i++){
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        //vectors can be compared
        if(freq == window)result.emplace_back(0);
        for(int i = p_leng; i < s_leng; i++){
            window[s[i - p_leng] - 'a']--;
            window[s[i] - 'a']++;
            if(freq == window)result.emplace_back(i - p_leng + 1);
        }
        return result;
    }
};