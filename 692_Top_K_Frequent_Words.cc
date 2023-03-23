/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.*/
//the standard way is min-heap(implemented by priority_queue)
//still need a map to record the word count
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //min_heap
        //SC O(k), TC O(nlogk)
        unordered_map<string, int> freq;
        for(auto w:words){
            freq[w]++;
        }
        auto comp = [&](const pair<string, int>& a, const pair<string, int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> my_pq;
        my_pq pq(comp);

        for(auto w: freq){
            pq.emplace(w.first, w.second);
            if(pq.size() > k)pq.pop();
        }

        vector<string> result;
        while(!pq.empty()){
            result.insert(result.begin() ,pq.top().first);
            pq.pop();
        }
        return result;
    }
};