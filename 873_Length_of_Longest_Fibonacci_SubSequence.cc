/*
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

 

Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].*/
//credit to lee215
//https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/solutions/152343/c-java-python-check-pair/
//TC O(N^2logM), where M is the max(A)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int res = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                int a = arr[i];
                int b = arr[j];
                int l = 2;
                while(s.count(a + b)){
                    b = a+ b;
                    a = b - a;
                    l++;
                }
                res = max(res, l);
            }
        }
        return res > 2? res:0;
    }
};

//TC O(N^2), credit to lee215
class Solution{
        int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];
        for (int j = 0; j < N; ++j) {
            m[A[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};