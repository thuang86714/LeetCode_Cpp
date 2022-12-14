/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.*/
/*
Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        //brute force-->O(N^2) Try all possible combination;
        int res= 0;
        for (int l=0; l < height.size(); l++){
            for (int r = l+1; r < height.size(); r++){
                int water = (r - l) * std::min(height[r], height[l]);
                res = std::max(res, water);
            }
        }
        return res;    
    }
    
};
