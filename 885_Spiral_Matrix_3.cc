/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.*/
//https://leetcode.com/problems/spiral-matrix-iii/solutions/158970/c-java-python-1-1-2-2-3-3-steps/
//credit to lee215
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>> res = {{r, c}};
        int dx = 0, dy =1, temp;
        for(int n = 0; res.size() < rows*cols; n++){
            for(int i = 0; i < n/2+1; i++){
                r += dx;
                c += dy;
                if(0 <= r && r < rows && 0 <= c&& c < cols){
                    res.push_back({r, c});
                }
            }
            temp = dx, dx = dy, dy = -temp;
        }
        //the starting point must fall in the grid
        return res;
    }
};
