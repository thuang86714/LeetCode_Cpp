/*Given an integer array nums, return all the triplets 
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
 and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/
/*
Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/
//credit to kun596
// time complexity O(NlogN)+ O(N^2)--> O(N^2), space complexity O(1) or O(N), 
//depends on sorting implementation
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        std::sort(nums.begin(), nums.end());//time complexity O(NlogN)
        for (int i = 0; i < nums.size(); i++){
            int target = -1*nums[i];
            int front = i +1;
            int back = nums.size()-1;
            while (front < back){
                int sum = nums[front]+ nums[back];
                // Finding answer which start from number num[i]
                if (sum < target){
                    front++;
                }
                else if (sum > target){
                    back--;
                }
                else {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1]) front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]){
                i++;
            } 
        }
        return res;
    }
}