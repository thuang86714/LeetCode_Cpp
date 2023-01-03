/*
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 typically using all the original letters exactly once.*/
 /*Example:
 Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
//naive method would be sort the strs[i] and compare, time complexity would be 
//O(i*avg_len*logavg_len);
//naive method, credit to jianchao-li
//Use an unordered_map to group the strings by their sorted counterparts. 
//Use the sorted string as the key and all anagram strings as the value.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s:strs){
            string temp = s; //the idea of pass by value
            std::sort(temp.begin(), temp.end());//if two strings are anagram, they should be identical after sorted
            mp[temp].push_back(s);
        }
        //since the return require vector, we iterate all elements in mp to a vector
        vector<vector<string>> res;
        for (auto p : mp){
            res.push_back(p.second);
        }
        return res;
    }
};