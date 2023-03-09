/*
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

 

Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).*/
//credit to karan_8082
//SC o(1), tc o(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //looks like a dp problem
        if(nums.size()==1 || (nums.size()==2 && nums[0]!=nums[1]))return nums.size();
        int peak = 1, valley =1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]>nums[i-1]) peak = valley+1;
            else if(nums[i] < nums[i-1]) valley = peak+1;
        }
        return max(peak, valley);
    }
};