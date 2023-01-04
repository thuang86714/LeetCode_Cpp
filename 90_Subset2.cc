/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]*/
//very similar to 78. Subset1
// time complexity is the same O(n*pow(2,n))
class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());//must be sorted to make the duplicate adjacent to one another
        std::vector<std::vector<int> > res;
		std::vector<int> temp;
		recurWithDup(res, nums, temp, 0);
		return res;
    }
private:
	void recurWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &temp, int begin) {
		res.push_back(temp);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { //the 
				temp.push_back(nums[i]);
				recurWithDup(res, nums, temp, i + 1);
				temp.pop_back();
			}
	}
};