/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]*/
//https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/614673/c-easy-to-understand-o-n-hashmap-cumulative-sum/
//akshit0699
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int i = 0, cur = 0, rem = 0, count = 0;
        int n = nums.size();
        if(n==0)return 0;
        unordered_map<int, int> map;
        map[0] = 1;
        while(i < n){
            cur += nums[i++];
            int rem = cur%k;
            if(rem < 0)rem +=k;
            if(map.find(rem) !=map.end()){
                count+=map[rem];
            }
            map[rem]++;
        }
        return count;
    }
};