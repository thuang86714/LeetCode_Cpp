/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true*/
//credit to OldCodingFarmer
//basically using recursive(or dfs in this case) to brute force all elements
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (dfs(board, word, i, j))return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j){
        if (!word.size())return true;
        //going to check boundry and if board[i][j] match word[0]
        if (i < 0 || j < 0 || i >= board.szie() || j >= board[0].size() || board[i][j] != word[0]){
            return false;
        }
        char temp = baord[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, s, i+1, j) || dfs(board, s, i-1, j) || dfs(board, s, i, j+1) || dfs(board, s, i, j-1); 
        board[i][j] = temp;
        return ret;
    }
};