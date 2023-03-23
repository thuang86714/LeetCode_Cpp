/*Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/
//TC o(n), SC o(1)
//https://leetcode.com/problems/subarray-product-less-than-k/solutions/108861/java-c-clean-code-with-explanation/
//credit to alexander
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0)return k;
        int count = 0;
        int product = 1;
        for(int left = 0, right = 0; right < nums.size(); right++){
            product *= nums[right];
            while(left <= right && product >= k){
                product /= nums[left];
                left++;
            }
            count = count + right - left + 1; 
        }
        return count;
    }
};