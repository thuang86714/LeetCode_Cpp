/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4*/
//credit to neetcode
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        return quickSelect(0, nums.size()-1, nums, k);
    }
private:
    int quickSelect(int left, int right, vector<int>& nums, int k){
        int pivot = nums[right];
        int p = left;
        for (int i = left; i < right; i++){
            if (nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[right], nums[p]);
        
        if(p > k){
            return quickSelect(left, p-1, nums, k);
        }else if (p < k)
        {
            return quickSelect(p+1, right, nums, k);
        }else{
            return nums[p];
        }
        
    }
};