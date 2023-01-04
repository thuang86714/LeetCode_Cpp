/*
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, 
respectively.
You must solve this problem without using the library's sort function.
Example:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/
//credit to nullptr_c
/*
    1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid != 0 || 2
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*basically any sorting algos with space complexity O(1) would do; Bubble Sort-->O(n^2), Selection Sort-->O(n^2), Insertion Sort-->O(n^2), Heap Sort-->O(nlogn)*/
        //but since there are only 3 known numbers here, it could be even simpler
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){//Mid <= High is our exit case
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};