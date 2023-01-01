/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target 
is less than 150 combinations for the given input.
Example:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.*/
//credit to KnockCat
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(candidates, target, temp, res, 0);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& res, int i ){
        //here comes the base case
        if (target==0){
            res.push_back(temp);
            return;
        }
        while( i < candidates.size() && target - candidates[i]>=0){
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], temp, res, i);
            ++i;
            temp.pop_back();
        }
    }
};
