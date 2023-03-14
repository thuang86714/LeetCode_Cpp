/*
A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/
//credit to aryanttripathi
//https://leetcode.com/problems/subarray-sum-equals-k/solutions/1759909/c-full-explained-every-step-w-dry-run-o-n-2-o-n-two-approaches/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int i = 0; i < n; i++){
            if(prefix[i] == k)ans++;

            if(map.find(prefix[i] - k) != map.end()){
                ans += map[prefix[i] - k];
            }

            map[prefix[i]]++;
        }
        return ans;
    }
};