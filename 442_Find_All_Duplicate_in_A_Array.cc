/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]*/
//https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/775798/c-four-solution-o-n-n-to-o-n-explain-all/
//credit to suman_buie
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0)ans.emplace_back(abs(nums[i]));
            nums[abs(nums[i]) - 1] = (-1)* nums[abs(nums[i]) - 1];
        }
        return ans;
    }
};