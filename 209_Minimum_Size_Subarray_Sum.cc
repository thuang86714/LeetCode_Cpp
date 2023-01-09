/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
*/
//credit to jianchao-li
/*
The O(n) solution is to use two pointers: l and r. First we move r until we get a sum >= s,
 then we move l to the right until sum < s. In this process, store the minimum length 
between l and r. Since each element in nums will be visited by l and r for at most once. 
This algorithm is of O(n) time.*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L =0;
        int R = 0;
        int sum =0;
        int len = INT_MAX;
        while(R < nums.size()){
            sum += nums[R++];
            while(sum >= target ){
                len = min(len, R-L);
                sum -= nums[L++];
            }
        }
        return len == INT_MAX? 0: len;
    }
};
//https://leetcode.com/problems/minimum-size-subarray-sum/solutions/59090/c-o-n-and-o-nlogn/