/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/
/*
Example and Constraints:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Constraint:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are "unique".
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l= 0; 
        int r = nums.size()-1;
        //binary search
        
        while(l <= r){// "=" operator is for nums.size()=1
            int mid = (l+r)/2;
            if (nums[mid]==target){
                return mid;
            }
            //left sorted portion
            if (nums[l]<=nums[mid]){
                if(target > nums[mid] || target < nums[l]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }else{
                if (target > nums[r] || target < nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};