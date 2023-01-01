/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
Example:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/
//partial credit to NUMBART
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> res(2,-1); //for the out of bound answer[-1, -1]
        while (l<=r){
            int mid = (l+r)/2;
            if (target > nums[mid])l = mid+1;
            else{
                if(target == nums[mid])res[0]= mid;
                    r = mid-1;
                
            }
        }
        l = 0, r = nums.size()-1;//dont for get the "-1" in case of overflow
        while (l<=r){
            int mid = (l+r)/2;
            if(target < nums[mid])r = mid-1;
            else{
                if(target == nums[mid])res[1]= mid;
                    l = mid+1;
                
            }
        }
        return res;
    }
};