/*
You are given an integer array nums. 
You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.\
Example:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.*/
//credit to rounak217
/*
Greedy: The idea is to iterate backwards, i.e., right to left, and keep track of
 the minimum jump length required, i.e., minjump, at a position.*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minjump = 0;
        bool res = false;
        for (int i = nums.size()-2; i >= 0 ; i --){
            minjump++;
            if (nums[i] >= minjump){
                minjump= 0;
            }
        }
        //res = (minjump ==0)? true: false; //doing something cool but useless
        return (minjump == 0);
    }
};