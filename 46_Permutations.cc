/*
Given an array nums of distinct integers, 
return all the possible permutations. You can return the answer in any order.
Example:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.*/
//backtracking and recursive needed;
//credit to https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteRecursive(nums, 0, res);
        return res;
    }
    void permuteRecursive(vector<int>& nums, int begin, vector<vector<int>> &result){
        if (begin >= nums.size()){
            // one permutation instance
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            permuteRecursive(nums, begin+1, result);
            //reset;
            swap(nums[begin], nums[i]);
        }
    }
};