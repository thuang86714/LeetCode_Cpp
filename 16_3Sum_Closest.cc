/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.*/
/*
Example:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/
// brute force would be time complexity O(N^3), for Combination n of 3
//better solution is sorting + two pointers
//credit to akashkumar201
#include <cmath> //std::abs()
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0]+ nums[1]+ nums[2];
        
        for (int i=0; i< n-2; i++){
            int k = i+1;
            int j = n-1;
            while (k < j){
                int temp = nums[i]+ nums[k]+ nums[j];
                if (std::abs(temp - target) < std::abs(sum - target)){
                    sum = temp;
                }
                if (temp < target){
                    k++;
                }else if(temp > target){
                    j--;
                }else{
                    return target;
                }
            }
            
        }
        return sum;
    }
    
};