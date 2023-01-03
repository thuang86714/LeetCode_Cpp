/*
Given a positive integer n, generate an n x n matrix 
filled with elements from 1 to n2 in spiral order.*/
/*
Example:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]*/
//credit to KnockCat && gm271312
//remember to check to boundry
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int column1= 0;
        int row1 = 0;
        int column2 = n-1;
        int row2 = n-1;
        int val = 0;
        vector<vector<int>> result(n, vector<int>(n));
        while (row1<= row2 && column1 <= column2){ //what if (val <= n*n)?
            for(int i = column1; i <= column2; i++)//left to right move,row is fixed
                result[row1][i] = ++val;
            for(int i = row1 + 1; i <= row2; i++)//top to bottom move, column is fixed 
                result[i][column2] = ++val;
            for(int i = column2 - 1; i >= column1; i--)//right to left move, row is fixed
                result[row2][i] = ++val;
            for(int i = row2 - 1; i > row1; i--)//bottom to top move, column is fixed
                result[i][column1] = ++val;
            column1++;
            row1++;
            column2--;
            row2--;
        }
        return result;
    }
};