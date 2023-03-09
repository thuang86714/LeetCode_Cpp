/*
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
Example 2:

Input: n = 0
Output: 1*/
//credit to KJer
//https://leetcode.com/problems/count-numbers-with-unique-digits/solutions/83056/share-my-0ms-c-solution-with-proof-and-explanation/
//P(n, r) = n * (n - 1) * (n - 2) * ... * (n - r + 1); P (n取r)
//A(n) = P(10,n) - P(9,n-1) = 9 * P(9,n-1)
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        for(int i = 0; i < n; i++){
            sum += 9 * permutation(9, i);
        }
        return sum;
    }
private:
    int permutation(int n, int r){
        if(r==0){//base case
            return 1;
        }else{
            return n*permutation(n-1, r-1);
        }
    }
};