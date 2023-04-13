//credit to lee215
//https://leetcode.com/problems/longest-mountain-in-array/solutions/135593/c-java-python-1-pass-and-o-1-space/
//2-pass solution
/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n, 0), down(n ,0);
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[i+1]){
                down[i] = down[i + 1]+1;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 &&arr[i] > arr[i - 1])up[i] = up[i-1] + 1;
            if(up[i] && down[i])res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};

//advanced: 1-pass
class Solution{
public:
        int longestMountain(vector<int> A) {
        int res = 0, up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (down && A[i - 1] < A[i] || A[i - 1] == A[i]) up = down = 0;
            up += A[i - 1] < A[i];
            down += A[i - 1] > A[i];
            if (up && down) res = max(res, up + down + 1);
        }
        return res;
    }
};