/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.*/
/*
Example:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].*/
//credit to Cosmic_Phantom
class Solution {
public:
    //using sorting + while traversing all elements--> time complexity O(nlogn) 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() <= 1)return intervals;
        sort(intervals.begin(), intervals.end());//sort the vector by the first element of each pair
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i ++){
            //if intervals are overlapping
            if (result.back()[1] >= intervals[i][0])result.back()[1] = max(result.back()[1], intervals[i][1]);
            else result.push_back(intervals[i]);
        }
        return result;
        
        
    }
};