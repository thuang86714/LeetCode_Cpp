/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 
on the next row.
Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).*/
//it's a DP-Bottom-Up-Space Optimized approach
//credit to stellari
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());//dp would store every pathsum of every path, 
        //we directly store the lowest layer into dp as the base case to start
        for(int layer = n-2; layer >= 0; layer--){//for all layers, except the lowest one
            for(int i = 0; i <=layer; i++){//for all element in a layer && num of elements of each layer == layer
                dp[i] = min(dp[i], dp[i+1])+ triangle[layer][i];
            }
        }
        return dp[0];
    }
};
/*
Time Complexity: O(n²)
Space Complexity: O(n)*/
//recursive solution would except time limit
//https://leetcode.com/problems/triangle/solutions/2146264/c-python-simple-solution-w-explanation-recursion-dp/