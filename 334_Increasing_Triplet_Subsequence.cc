/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)return false;
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for(int n : nums){
            if(n <= num1){
                num1 = n;
            }else if(n <= num2){
                num2 = n;
            }else{
                return true;
            }
        }
        return false;

    }
};