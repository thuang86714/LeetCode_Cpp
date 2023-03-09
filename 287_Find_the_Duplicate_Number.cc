/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //binary search
        //time complexity O(nlogN), space complexity O(1)
        int low = 1, high = nums.size()-1, count;
        while(low <= high){
            int mid = (low + high)/2;
            count = 0;
            for(int n: nums){
                if(n <= mid){
                    count++;
                }
            }
            if(count <= mid){//go binary search on the left
                low = mid+1;
            }else{
                high = mid-1;//go binary search on the right
            }

        }
        return low;
    }
};