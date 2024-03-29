/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.*/\
//https://leetcode.com/problems/stone-game/solutions/154610/dp-or-just-return-true/
class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)dp[i][i] = p[i];
        for(int d = 1; d < n; d++){
            for(int i = 0; i <(n-d); i++){
                dp[i][i + d] = max(p[i] - dp[i+1][i+d], p[i+d] - dp[i][i+d-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};
/*
dp[i][j] actually means maximum(alex stone - lee stone) and maximum(lee stone - alex stone) alternatively, depending on who picks from piles[i]~piles[j] first.
If alex picks from piles[i]~piles[j] first, then dp[i][j] means maximum(alex stone - lee stone);
If Lee pick from piles[i]~piles[j] frist, then dp[i][j] means maximum(lee stone - alex stone) .*/