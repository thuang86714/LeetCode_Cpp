/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
Example:
Input: s = "3+2*2"
Output: 7*/
#include <sstream>
class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');//must include header <sstream>
        long long int total = 0, term = 0, n;
        char op;
        while(in >> op){
            if(op == '+' || op =='-'){
                total += term;
                in >> term;
                term *= 44 - op;//if op == '+', asiic = 43, op == '-', asiic = 45
            }else{
                in >> n;
                if(op == '*'){
                    term *= n;
                }else{
                    term /= n;
                }
            }
        }
        return total;
    }
};