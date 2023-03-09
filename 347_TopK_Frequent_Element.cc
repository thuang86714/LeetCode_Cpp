/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.*/
//credit to sxycwzwzq
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int n: nums){
            count[n]++;
        }

        priority_queue<pair<int, int>> freq;//queue is a FIFO container, and prior_q would sort automatically
        vector<int> res;

        for(auto it = count.begin(); it != count.end();it++){
            freq.push(make_pair(it->second, it->first));
            if(freq.size() > count.size()-k){//
                res.push_back(freq.top().second);
                freq.pop();
            }
        }
        return res;
    }
};
// there's one more solution with time complexity O(n), credit to ChrisTrompf https://leetcode.com/problems/top-k-frequent-elements/solutions/147549/Short-and-simple-c++-o(n)-solution.-No-need-to-burn-nlogn-on-the-sort
//the key idea is nth_element, but can't understand the cmp part
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    std::vector<int> ret;
    ret.reserve(nums.size());
    for (auto n : nums) {
      if (1 == ++freq[n]) {
        // Count the frequency for each int, storing each new int as we go
        ret.push_back(n);
      }
    }

    // Piviot around the kth element using custom compare. Elements are not sorted, just
    // reordered such that all elements in the range [0, k] are greater than those in [k + 1, n)
    // This is an (average) O(n) operation
    std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), [&freq] (int l, int r) -> bool {
        return freq[l] > freq[r];
      });
    ret.resize(k);
    return ret;
  }