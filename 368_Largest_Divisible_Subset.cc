/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1)return nums;
        int flag =0;
        sort(nums.begin(), nums.end());
        if (nums[0] != 1){
            nums.push_back(1);
            flag = 1;
        }
        sort(nums.begin(), nums.end());
        int i, j;
        int dp[nums.size()][2];
        for(int i = nums.size()-1; i >=0; i--){
            dp[i][0]=0;
            dp[i][1] = i;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j]%nums[i] == 0){
                    if(dp[j][0]>dp[i][0]){
                        dp[i][0] = dp[j][0];
                        dp[i][1] = j;
                    }
                }
            }
            dp[i][0]++;
        }
        i = 0;
        vector<int> res;
        res.push_back(nums[i]);
        while(dp[i][1]!=i){
            i = dp[i][1];
            res.push_back(nums[i]);
        }
        if(flag==1)res.erase(res.begin());
        return res;
    }
};