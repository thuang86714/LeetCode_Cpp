/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].*/
//https://leetcode.com/problems/maximum-length-of-repeated-subarray/solutions/1324248/c-python-dp-kmp-hashing-solutions-clean-concise-o-nlogn/
//credit to hiepit
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //classic Longest Common Substring problem, dp; TC = SC = O(m*n)
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1));
        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //classic Longest Common Substring problem, dp; TC = SC = O(m*n)
        //space optimized version O(n)
        int m = nums1.size();
        int n = nums2.size();
        if (n > m) return findLength(nums2, nums1);
        vector<int> dp(m + 1), predp(m + 1);
        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[j] = predp[j - 1] + 1;
                }else{
                    dp[j] = 0;
                }
                ans = max(ans, dp[j]);
            }
            swap(dp, predp);
        }
        return ans;
    }
};