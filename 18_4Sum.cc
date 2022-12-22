/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]*/
//first idea: as 3 sum, sorting + two pointers
//credit to kun596, as for 3Sum. 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> res;
        std::sort(nums.begin(), nums.end());
        if (nums.size()<4){return res;}
        for (int i = 0; i < nums.size(); i++){// even  for NSum, the logic is the same
            int target_of_3 = target - nums[i];
            for (int j = i+1; j< nums.size(); j++){
                int target_of_2 = target_of_3 - nums[j];
                int front = j+1;
                int back = nums.size()-1;
                while (front < back){
                    int two_sum = nums[front] + nums[back];
                    if (two_sum < target_of_2){
                        front++;
                    }else if(two_sum > target_of_2){
                        back--;
                    }else{
                        vector<int> quad= {nums[i], nums[j], nums[front], nums[back]};
                        res.push_back(quad);
                        while (front < back && nums[front]== quad[2]){front ++;}
                        while (front < back && nums[back]== quad[3]){back--;}
                    }
                }
                while (j+1 < nums.size() && nums[j+1]==nums[j]){j++;}
            }
            while (i + 1< nums.size() && nums[i+1]== nums[i]){i++;}
        }
    return res;
    }
    
};