/*
Given an integer array nums, find a subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.*/
//credit to flybit
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.empty())return 0;
        int MAX = INT_MIN;//we will return this
        int curMax = 1;
        int curMin = 1;//this exists for the negatives int in the nums;
        for(auto n: nums){
            if(n < 0){
                swap(curMax, curMin);
            }
            curMax = max(curMax*n, n);
            curMin = min(curMin*n, n);
            MAX = max(curMax, MAX);//to see if current Max is larger than record max
        }
        return MAX;
    }
};
//https://leetcode.com/problems/maximum-product-subarray/solutions/203013/c-o-n-time-o-1-space-solution-with-explanation/