/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
Example:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9*/
//credit to archit91
//we are using stack for this problem
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& t: tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/" ){
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                if(t == "+") op1 = op2 + op1;
			    if(t == "-") op1 = op2 - op1;
			    if(t == "/") op1 = op2 / op1;
			    if(t == "*") op1 = op2 * op1; 
                s.push(op1);

            }else{
                s.push(stoi(t));  // stoi - converts from string to int   
            }

        }
        return s.top();
    }
};
/*
The reverse polish is a mathematical notation in which operators follow their operands. So, we will get the operands first and then the operators.

So, we need to store all the previous operands in order that we receive. If we get a operator at anytime, we know that it must be operated on the previous two operands. The result that we get will act as operand for future operations and so it must be stored as well. We can use a stack to store all the operands. The algorithm can be summarized as -

If the current token is a operand (number), push it into the stack
If the token is a operator, pop the top two operands from the stack. Find the result of the operation using the operator and two operands and push the result back into stack
Finally, the stack will contain the result of evaluated reverse polish expression.*/
//https://leetcode.com/problems/evaluate-reverse-polish-notation/solutions/1229370/short-simple-solution-w-explanation-o-n-o-1-space-solutions/