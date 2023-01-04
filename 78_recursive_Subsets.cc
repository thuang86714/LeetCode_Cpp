/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]*/
//credit to in-jianchao-li we trust;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //backtracking + res.push_back("");? yep
        vector<vector<int>> result;
        vector<int> sub;
        recursive(nums, 0, result, sub);
        return result;
    }
private:
    void recursive(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& sub){
        result.push_back(sub);//at this point, sub is empty, so we push_back [] into result;
        for(int j = i; j< nums.size(); j++){
            sub.push_back(nums[j]);
            recursive(nums, j+1, result, sub);
            sub.pop_back();
        }
    }
};