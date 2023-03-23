/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]*/
class Solution {
public:
        vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size()-k;
        /*
        why init right = A.size()-k, not A.size()?
        if not, in the first round of the following while loop*/
        while (left < right) {
            int mid = (left + right) / 2;// binary search part
            if (x - A[mid] > A[mid + k] - x)//sliding window part, for window size = k
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + right, A.begin() + right + k);
        //return vector<int>(A.begin()+left, A.begin()+left+k);
    }
};