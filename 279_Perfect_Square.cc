/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
*/
//credit to NeetCode
//DP+bottom up: 1 = 1, 2 = 1+1, 3 = 1+1+1 = 2+1, 4 = 2^2, 5 = 2^2+1 = 4+1; dp[target] = min(dp[target], dp[target - square]+1)
class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        //dp[i] = the least number of perfect square numbers 
        // which sum to i. Note that dp[0] is 0.
        for(int i =1; i <= n; i++){//we are using two for loop to build the needed value bottom up
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], dp[i - j*j]+1);
                //For each i, it must be the sum of some number (i - j*j) and 
                // a perfect square number (j*j).
            }
        }
        return dp.back();
    }
};//the time complexity is O(n^3/2)
//other solutions: https://leetcode.com/problems/perfect-squares/solutions/71488/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics/
//credit to davidtan1890's and zhukov
class Solution 
{  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  //if n is a perfect square, then sqrt(n) should be an int, nothing would be truncated
        return (sqrt_n*sqrt_n == n);  
    }
    
public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if(is_square(n)) 
        {
            return 1;  
        }
        
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0; & is operator for binary and, would return Copies a bit to the evaluated result if it exists in both operands
        {
            n >>= 2;  //binary right shift, this case means divided by 4(2^2)
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }
        
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  
        
        return 3;  
    }  
}; 