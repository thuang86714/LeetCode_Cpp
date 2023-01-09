/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.*/
/*
Credit to karthickpdy and gangan
Most people have figured out the binary search solution but are not able to understand how its 
working. I will try to explain it simply. What we are essentially doing is going in the direction
 of the rising slope(by choosing the element which is greater than current). 
 How does that guarantee the result? Think about it, there are 2 possibilities.
 a) rising slope has to keep rising till end of the array 
 b) rising slope will encounter a lesser element and go down.
In both scenarios we will have an answer. In a) the answer is the end element because 
we take the boundary as -INFINITY b) the answer is the largest element before the slope falls.
 Hope this makes things clearer.*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;//constraint: 1 <= nums.length <= 1000
        int L = 0;
        int R = nums.size()-1;
        while(L < R){
            int mid = (L+R)/2;
            int mid2 = mid+1;//we are trying to find the rising slope within the array
            if(nums[mid] < nums[mid2]){
                L = mid+1;
            }else{
                R = mid;
            }
        }
        return L;
    }
};