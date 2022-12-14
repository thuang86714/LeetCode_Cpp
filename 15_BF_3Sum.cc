/*Given an integer array nums, return all the triplets 
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
 and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/
/*
Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //brute force solution; iterate through all elements in the given vector, O(N^3);
        //not able to handle duplication
        std::vector<vector<int>> res;
        for (int l = 0; l < nums.size(); l++){
            for (int r = l+1; r < nums.size(); r++){
                for (int i= l +2; i < nums.size(); i++){
                    if (nums[l]+nums[r]+nums[i]==0){
                        vector<int> temp = {nums[l], nums[r], nums[i]};
                        res.push_back(temp);
                    }else{
                        continue;
                    }
                }
                
            }
        }
        return res;
    }
};