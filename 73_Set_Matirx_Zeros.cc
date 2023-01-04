/*
Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.

You must do it in place.
Example:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]*/
//credit to mzchen and fudonglai
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isColZero = false;
        bool isRowZero = false;
        for (int i = 0; i < matrix.size(); i++){//check the first column, but dont turn others just yet
            if(matrix[i][0]==0){
                isColZero = true;
                break;
            }
        }
        for(int i= 0; i < matrix[0].size(); i++){//check the first row, but dont turn others just yet
            if(matrix[0][i]==0){
                isRowZero = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++){//check except the first row and column
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++){//process except the first row and column
            for (int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if (isColZero){//process the first column
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0]=0;
            }
        }
        if (isRowZero){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i]=0;
            }
        }
    }
};