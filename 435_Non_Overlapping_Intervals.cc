/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/
bool comp(vector<int> &a, vector<int> &b){//must put comp before Solution
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return 0;
        int ans = -1;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> prev = intervals[0];
        for(vector<int> i: intervals){
            if(prev[1] > i[0]){ans++;}
            else{prev = i;}
        }
        return ans;
    }
};