/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
 => (sum_j - sum_i) % k = 0
 => sum_j % k - sum % k = 0
 => sum_j % k = sum_i % k    <Relation derived !!!>*/
 class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int preSum = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            preSum %= k;
            if(preSum == 0 && i)return true;

            if(map.find(preSum) != map.end()){
                if(i - map[preSum] > 1)return true;
            }else map[preSum] = i;
        }
        return false;
    }
};