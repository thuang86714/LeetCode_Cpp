/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take
 to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.*/
/*
Example:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down*/
/*
We start at (0, 0) cell and move to (m-1, n-1) cell.
We need to make m-1 down-moves and n-1 right-moves to reach the destination cell.
Thus, we need to perform a total number of m+n-2 moves.
At each cell along the path, we can choose either the right-move or down-move and we 
need to find the number of unique combinations of these choices (which eventually leads 
to unique paths).
This is nothing but calculating the number of different ways to choose m-1 down-moves 
and n-1 right-moves from a total of m+n-2 moves. Mathematically, 
this can be represented as - (m+n-2)!/((n-1)*(m-1))
*/
//credit to archit91
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};