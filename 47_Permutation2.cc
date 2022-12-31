/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.
Example:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/
//credit to guoang
//Basically your idea is sorting first and then applying same method for permutation I
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        //sorting is use to ensure that identical elements are adjacent to each other
        recursive(nums,0, nums.size(), res);
        return res;
    }
private://as a good habit
    void recursive(vector<int> nums, int begin, int size, vector<vector<int> > &res){
        /*Note that nums is passed by value, so any action performed by function calls 
        further down will not impact anything in the current level. */
        if(begin == size-1){//base case
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < size; i++){
            if (i != begin && nums[i]==nums[begin])continue;//preventing duplicate
            swap(nums[i], nums[begin]);
            recursive(nums, begin+1, size, res);
        }
    }
};