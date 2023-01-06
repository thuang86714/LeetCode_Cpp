/*
The approach and code will be very similar. The only change is every time we calculate 
the result for numTrees(i), we store the result in dp[i] and only then return it.
 After that, each time we encounter dp[i] that's already calculated, we can directly 
 return the result. This way, we won't solve for the same numTrees(i) multiple times.*/
//credit still goes to archit91
class Solution {
public:
    int dp[20]{};//20 because the constraint of n is 0 <= n <=19
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp[n]) return dp[n];//we store the value of numTree() here
        for(int i = 1; i <= n; i++) 
            dp[n] += numTrees(i-1) * numTrees(n-i);
        return dp[n];
    }
};
/*
Time Complexity : O(N2)
Here we calculate numTrees(i) (for 1<=i<=N) only once and memoize it which will take O(N). 
For calculating each of numTrees(i), we need N iterations to calculate 
numTrees(0)*numTrees(i) + numTrees(1)*numTrees(i-1) + numTrees(2)*numTrees(i-2)+ ... + numTrees(i)*numTrees(0). 
Thus, the overall time complexity becomes O(N*N).
Space Complexity : O(N), required for recursion and memoization*/

//Also, there's Catalan NUmber
class Solution {
public:
    long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
};