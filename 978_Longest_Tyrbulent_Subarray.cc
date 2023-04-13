/*
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 

Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]*/
//https://leetcode.com/problems/longest-turbulent-subarray/solutions/221929/c-java-6-lines-flip-the-sign/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 0;
        for(int i = 0, count = 0; i+1 < arr.size(); i++, count *= -1){
            if(arr[i] > arr[i+1]){
                count = count > 0? count+1:1;
            }else if(arr[i] < arr[i+1]){
                count = count <0? count-1:-1;
            }else{//the corner case arr[i] == arr[i+1]
                count = 0;
            }
            res = max(res, abs(count));
        }
        return res +1;
    }
};