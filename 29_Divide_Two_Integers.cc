/*
Given two integers dividend and divisor, divide two integers without using multiplication,
 division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit 
signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 231 - 1,
 then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.*/
//credit to jianchao-li
#import <climits>//for MACRO INT_MIN and INT_MAX
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        /*brute force while (dividend - divisor > 0){
            dividend = dividend - divisor;
            quotient++;
        }
        */
        //using bitshift skills would make it faster
        long dvd = labs(dividend), dvs = labs(divisor), quotient = 0; //long int are needed for 2^31-1 and -2^31
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        //bitwise XOR; if dividend > 0 -->1, dividisor > 0 --> 1, ^ would be 0
        //bitwise XOR; if dividend < 0 -->0, dividisor < 0 --> 0, ^ would also be 0
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {//the binary of temp shift left for 1 bit, meaning temp*(2^1)
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            quotient += m;
        }
        return sign * quotient;
          
    }
};