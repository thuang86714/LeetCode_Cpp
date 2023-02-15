/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //time complexity O(n), and space complexity O(1)
        vector<int> res(nums.size());
        int prefix = 1, postfix = 1;

        for(int i = 0; i < nums.size(); i++){
            res[i] = prefix;
            prefix *= nums[i];
        }

        for(int j = nums.size()-1; j >= 0; j--){
            res[j] *= postfix;
            postfix *= nums[j];
        }

        return res;
    }
};
//Follow up: Can you solve the problem in O(1) extra space 
//complexity? (The output array does not count as extra space for space complexity analysis.)