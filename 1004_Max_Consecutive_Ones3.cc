/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/
//https://leetcode.com/problems/max-consecutive-ones-iii/solutions/247564/java-c-python-sliding-window/
//in comment section, credit to miaow
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right, left = 0, maxi = 0;
        for(right = 0; right < nums.size(); right++){
            if(nums[right] == 0)k--;
            if(k < 0){
                if(nums[left]==0)k++;
                left++;
            }
            if(k >= 0)maxi = max(maxi, right - left+1);
        }
        return maxi;

    }
};