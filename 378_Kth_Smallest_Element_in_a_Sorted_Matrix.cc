/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13*/
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/
//credit to hiepit
class Solution {
public:
    int n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();//only because it's a square
        //we are going to do binary search with SC O(1), O((M+N) * logD)
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int ans;
        while(left <= right){
            int mid = (left+right)/2;
            if(countEqualLess(matrix, mid) >= k){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }

        }
        return ans;

    }

    int countEqualLess(vector<vector<int>>& matrix, int mid){
        int count = 0;
        int c = n-1;
        for(int r = 0; r < n; r++){
            while(c >= 0 && matrix[r][c] > mid){// decrease column until matrix[r][c] <= x
                c--;
            }
            count += (c+1);
        }
        return count;
    }
};