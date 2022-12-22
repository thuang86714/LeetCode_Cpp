/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 Example:
 Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/
//using backtracking and recursive
/*
3 rules to follow for this question
1. only add open paranthesis if open <n
2. only add a closing paranthesis if closed < open
3. valid IIF open == closed == n*/
//credit to jianchao-li
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string paren;
        backtrack(n, 0, 0, res, paren);
        return res;
    }
private://as a good habit
    void backtrack(int n, int open, int closed, vector<string>& res, string paren){
        if (n == open && n==closed){
            res.push_back(paren);
        }else{
            if (open < n){
                backtrack(n, open+1, closed, res, paren+'(');
            }
            if (closed < open){
                backtrack(n, open, closed+1, res, paren+ ')');
            }
        }
    }
};