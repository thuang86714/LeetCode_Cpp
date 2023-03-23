/*
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

 

Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
*/
//https://leetcode.com/problems/split-array-into-consecutive-subsequences/solutions/106514/c-python-esay-understand-solution/
//credit to lee215
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size() < 3)return false;
        unordered_map<int, int> count, end;
        for(int i:nums)count[i]++;

        //in this follwoing for loop, we try to place i in subsequences
        for(int i:nums){
            if(count[i] == 0)continue;//this condition is valid cuz there's count[i+2]--;
            count[i]--;
            if(end[i - 1] > 0){// place a in an existing subsequence if possible
                end[i -1]--;
                end[i]++;
            }else if(count[i+1] > 0 && count[i+2] > 0){// place a in a new subsequence
                count[i+1]--;
                count[i+2]--;
                end[i+2]++;
            }else{// don't know where to place a? ---> false
                return false;
            }
        }
        return true;
    }
};