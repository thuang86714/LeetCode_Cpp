//credit to StefanPochman
//time complexity O(N);
class Solution {
public:
    int maxArea(vector<int>& height) {
        //start from the widest combination
        int water = 0;
        int l = 0 , r = height.size() - 1;
        while (l < r){
            int h = std::min(height[r], height[l]);
            water = std::max((r- l) * h, water);
            while(height[l] <= h && l < r)l++;
            while(height[r] <= h && l < r)r--;
        }
    return water;
    }
};