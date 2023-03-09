/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        //Let dp[i] is the longest increase subsequence of nums[0..i] which has nums[i] as the end element of the subsequence.
        for (int i = 1; i < size; i++){
            for(int j = 0; j < i ; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j]+1)dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
//Time: O(N^2), where N <= 2500 is the number of elements in array nums.
//Space: O(N)
//credit to hiepit, https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/