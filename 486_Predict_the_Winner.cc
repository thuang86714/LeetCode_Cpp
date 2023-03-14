//https://youtu.be/Tw1k46ywN6E?t=3622
//https://leetcode.com/problems/predict-the-winner/solutions/96829/dp-o-n-2-mit-ocw-solution-explanation/
//credit to kevin36, zzwcsong(left a useful but not entirely correct comment below), JackyD(left a corrective comment in zzwcsong's comment)
//TC O(n^2)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2 == 0)return true;
        vector<vector<int>> dp(n, vector<int> (n ,-1));
        int myMax = recur(nums, dp, 0, n-1);
        return 2*myMax >= accumulate(nums.begin(), nums.end(), 0);
    }

private:
    int recur(vector<int>& nums, vector<vector<int>>& dp, int left, int right){
        //base case
        if(left > right)return 0;
        if(dp[left][right] != -1)return dp[left][right];

        //our oppnent would choose optimally as we do, meaning they would leave the min value to us as our next step
        int a = nums[left] + min(recur(nums, dp, left + 1, right-1), recur(nums, dp, left + 2, right));
        int b = nums[right] + min(recur(nums, dp, left + 1, right - 1), recur(nums, dp, left, right - 2));
        dp[left][right] = max(a, b);

        return dp[left][right];
    }
};