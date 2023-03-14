/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.*/
//https://leetcode.com/problems/sort-characters-by-frequency/solutions/1503201/c-python-3-solutions-sorting-bucket-sort-o-n-clean-concise/
//credit to hiepit
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for(char c:s)count[c]++;
        
        vector<pair<int, char>> arr;
        for(auto& [c, freq]: count){
            arr.emplace_back(make_pair(freq, c));
        }

        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b){return a.first > b.first;});

        string answer;
        for(auto& [freq, c]: arr){
            answer.append(freq, c);
        }
        return answer;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int len = s.length();
        unordered_map<char, int> count;
        for(char c:s)count[c]++;
        
        vector<vector<char>> bucket(len+1);
        for(auto& [c, freq]: count){
            bucket[freq].emplace_back(c);
        }

        string answer;
        for(int freq = len; freq >= 1; freq--){
            for(char c:bucket[freq]){
                answer.append(freq, c);
            }
        }
        return answer;
    }
};