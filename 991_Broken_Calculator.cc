/*
There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

multiply the number on display by 2, or
subtract 1 from the number on display.
Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

 

Example 1:

Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.*/
//https://leetcode.com/problems/broken-calculator/solutions/1874851/c-easy-approach-proper-explanation/
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(startValue < target){
            count++;
            if(target%2)target+=1;
            else target /=2;
        }
        count += abs(startValue - target);
        return count;
    }
};