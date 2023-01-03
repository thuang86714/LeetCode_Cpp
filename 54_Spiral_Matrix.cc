/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]*/
//dont make it too complicated, no need BFS to get it done
//credit to rv237
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        vector<int> result;
        while(left <= right && top <= bottom){

            for(int i = left; i <= right && top <= bottom; i++)res.push_back(matrix[top][i]);
            top++;

            for(int i = top; i <= bottom && left <= right; i++)res.push_back(matrix[i][right]);
            right--;

            for(int i = right; i >= left && top <= bottom; i--)res.push_back(matrix[bottom][i]);
            bottom--;

            for(int i = bottom; i >= top && left <= right; i--)res.push_back(matrix[i][left]);
            left++;
        }
        return result;
    }
};