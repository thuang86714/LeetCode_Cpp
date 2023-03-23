//Sol 1 DP + recur
#define INF 1'000'000
class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int> (n+1, 0));
        return n > 1 ? 1 + count(1, n, 1, dp): 0;
    }

    int count(int curA, int n, int copiedA, vector<vector<int>> &dp){
        if(curA > n){
            return INF;//prevent buffer overflow
        }else if(curA == n){
            return 0;
        }else if(dp[curA][copiedA]){
            return dp[curA][copiedA];
        }else{
            int copy = 2 + count(curA + curA, n, curA, dp);
            int paste = 1 + count(curA + copiedA, n, copiedA, dp);
            return dp[curA][copiedA] = min(copy, paste);
        }
    }
        
};

//Sol 2 recur
class Solution{
public:
    int minSteps(int n){
        static const int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};//all prime that prime*prime < 1000
        if(n < n) return n == 1? 0: n;
        for(auto i: primes){
            if(n%i == 0)return i + miniSteps(n/i);
        }
        return n;
    }
}