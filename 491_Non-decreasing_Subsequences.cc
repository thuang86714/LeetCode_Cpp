/*
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]*/
//https://leetcode.com/problems/non-decreasing-subsequences/solutions/97124/c-dfs-solution-using-unordered-set/
//credit to emmm_
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() == 1)return {};
        vector<vector<int>> result;
        vector<int> temp;
        dfs(result, temp, nums, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int idx){
        if(temp.size() > 1)result.push_back(temp);
        unordered_set<int> hash;
        for(int i = idx; i < nums.size(); i++){
            if((temp.empty() || nums[i] >= temp.back()) && hash.find(nums[i]) == hash.end()){
                temp.push_back(nums[i]);
                dfs(result, temp, nums, i+1);
                temp.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};