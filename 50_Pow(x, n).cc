/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example:
Input: x = 2.00000, n = 10
Output: 1024.00000*/
//credit to Muyinyao and Anja
class Solution {
public:
    double myPow(double x, int n) {
        return recur(x, n, 1);
    }
    double recur(double x, int n, double res){
        if (n == 0) return res;
    
        if (n%2 != 0){//if int n is odd number
            if (n>0) res *= x;//then we change res to make int n a even number
            else res /= x;
        }
    
        return recur(x*x, n/2, res);
    }
};
