/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> count;
        for(int i = 0; i < s.length(); i++){
            count[s[i]] = i;
        }
        int maxi = 0, prev = -1;//0-indexed
        vector<int> result;
        for(int i= 0; i < s.length(); i++){
            maxi = max(maxi, count[s[i]]);
            if(maxi == i){
                result.emplace_back(maxi - prev);
                prev = maxi;
            }
        }
        return result;
    }
};