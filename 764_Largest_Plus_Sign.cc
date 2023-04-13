/*
You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.*/
class Solution {
public:
int DIR[5] = {0, 1, 0, -1, 0};
int dp[500][500][4] = {};//constraint n <= 500
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>> mineMap(n, vector<bool> (n, false));
        for(auto pos: mines){
            mineMap[pos[0]][pos[1]] = true;
        }
        int ans = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int plusSignSize = dpMaxArm(n, mineMap, r, c, 0);//could us plusSignSize = INT_MAX, but bear the risk of overflow
                for(int d = 1; d < 4; d++){
                    plusSignSize = min(plusSignSize ,dpMaxArm(n, mineMap, r, c, d));
                }
                ans = max(ans, plusSignSize);
            }
        }
        return ans;
    }

    int dpMaxArm(int n, vector<vector<bool>>& mineMap, int r, int c, int d){
        if(r < 0 || c < 0 || r >= n || c >= n || mineMap[r][c])return 0;//base case
        if(dp[r][c][d] != 0)return dp[r][c][d];
        return dp[r][c][d] = dpMaxArm(n, mineMap, r + DIR[d], c + DIR[d+1], d)+1;
    }
};