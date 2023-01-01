/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
Example:
*/
//credit to stanislav-iablokov

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //credit to stanislav-iablokov
        //using set().emplace().second
        vector<set<char>> rows(9), cols(9), sqrs(9);
        for (int i = 0; i< 9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    int num= board[i][j], d = (i/3)*3+(j/3);//(i/3)*3 is for the int quotient
                    if(!rows[i].emplace(num).second) return false;
                    if(!cols[j].emplace(num).second) return false;
                    if(!sqrs[d].emplace(num).second) return false;
                }
            }
        }
        return true;
    }
};