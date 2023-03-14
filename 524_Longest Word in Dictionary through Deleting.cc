/*
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"*/
//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/solutions/1077716/c-simple-intuitive-short-easy-to-read-solution-o-nm-time-o-1-space/
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for(string word:dictionary){
            if(canFormbyDelete(word, s)){
                if(result.length() < word.length() || (result.length() == word.length() && word < result)){
                    result = word;
                }
            }
        }
        return result;
    }
private:
    bool canFormbyDelete(string word, string s){
        int i =0, j = 0;
        while(i < word.length() && j < s.length()){
            if(word[i] == s[j])i++;
            j++;
        }
        return i == word.length();
    }
};