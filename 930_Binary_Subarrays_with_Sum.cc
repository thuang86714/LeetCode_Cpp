/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    
    int atMost(vector<int>& nums, int goal){
        if(goal < 0)return 0;
        int res = 0, i = 0;
        for(int j = 0; j < nums.size(); j++){
            goal -= nums[j];
            while(goal < 0){
                goal += nums[i++];
                
            }
            res += j - i +1;
        }
        return res;
    }
};