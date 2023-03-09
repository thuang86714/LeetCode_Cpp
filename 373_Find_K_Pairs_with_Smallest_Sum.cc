/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]*/
//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/596658/c-solution-with-diagram-explaination-for-beginners/
//credit to Leodicap99
//Time complexity is O(m*nlogk)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
            for(int i = 0; i < nums1.size(); i++){
                for(int j = 0; j < nums2.size(); j++){
                    int sum = nums1[i]+nums2[j];
                    if(pq.size()<k)pq.push({sum, {nums1[i], nums2[j]}});
                    else if(sum < pq.top().first){
                        pq.pop();
                        pq.push({sum, {nums1[i], nums2[j]}});
                    }else{
                        break;
                    }

                }
            }
            while(!pq.empty()){
                res.push_back({pq.top().second.first, pq.top().second.second});
                pq.pop();
            }
            reverse(res.begin(), res.end());
        return res;
    }
};