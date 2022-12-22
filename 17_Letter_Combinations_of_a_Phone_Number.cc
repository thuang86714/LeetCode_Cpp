/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/
/*
Example:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]*/
/*Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].*/
class Solution {
public:
//going to use rcursive and backtracking for this one
//credit to Sjai786
    const vector<string> keyboard = { //const since we dont want the content to be changed
        "", "", "abc", "def", "ghi", "jkl", //first two is "" because there's no corresponding char to 0 and 1 
        "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.length()==0){return {};}//save the trouble
        vector<string> res;//we will return this vector
        backtrack(0, digits,res, "");
        return res;
    }
    void backtrack(int idx, string &digits, vector<string>&res, string s){//doing backtracking here
        if(idx == digits.length()){res.push_back(s);}
        else {
            for (auto c : keyboard[digits[idx]-'0'])backtrack(idx+1, digits, res, s+c);
            /*here we do digits[idx]- '0' is because 
            typeof(digits[idx])== char, doing - '0' is to convert it from char to int.
            hence avoid the need of address sanitizer*/
        }    
            

        
    }

};