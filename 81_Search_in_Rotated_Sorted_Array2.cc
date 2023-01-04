/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
Example:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true*/
//credit to LeJas
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //very similar to Search 1, using binary search would give us time complexity O(logn)
        //but do bear in mind that there may be duplicate in nums this time, will need to handle it
        int left = 0, right = nums.size()-1, mid;
        while (left <= right){
            mid = (left + right)/2;
            if (nums[mid] == target)return true;
            if (nums[left] == nums[mid] && nums[right] == nums[mid]){//to figure out which interval target falls into 
                ++left;
                --right;
            }else if (nums[left] <= nums[mid]){
                if((target >= nums[left]) && (target < nums[mid])){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else {
                if((target > nums[mid]) && (target <= nums[right])){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }

            }
        }
        return false;
    }
};