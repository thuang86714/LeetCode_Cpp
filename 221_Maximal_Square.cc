class Solution {//not space optimal ver O(mn) for both space and time
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (matrix.empty()){
            return 0;
        }
        for (int i = 0; i < m; i++){
            for(int j =0 ; j < n; j++){
                if (!i || !j || matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j] - '0';
                }else{
                    dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    
                }
                size = max(size, dp[i][j]);
            }
            
        }
        return size*size;
    }
};

//space complexity O(2n)
class Solution{
public:
    int maximalSquare(vector<vector<char>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> pre(n, 0);
        vector<int> cur(n, 0);
        int size = 0;
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (!i || !j || matrix[i][j] == '0'){
                    cur[j] = matrix[i][j] - '0';
                }else{
                    cur[j] = 1 + min(pre[j-1] ,min(cur[j-1], pre[j]));
                }
            size = max(size, cur[j]);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
            
        }
        return size*size;
    }
};

//space complexity O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0, pre;
        vector<int> cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = cur[j];
                if (!i || !j || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre, min(cur[j], cur[j - 1])) + 1;
                    /*
                    pre here is equal to cur[j-1] for O(2n)
                    cur[j] here is pre[j]
                    cur[j-1] here is pre[j-1]*/
                }
                sz = max(cur[j], sz);
                pre = temp;
            }
        }
        return sz * sz;
    }
};