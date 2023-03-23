/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
*/
//https://leetcode.com/problems/maximum-swap/solutions/107073/c-one-pass-simple-fast-solution-1-3ms-o-n-time/
//credit to TimmyLu926
class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);
        int maxNum = -1, maxIdx = -1, leftIdx = -1, rightIdx = -1;
        for(int i = numstr.length()-1; i >= 0; i--){
            if(numstr[i] > maxNum){
                maxNum = numstr[i];
                maxIdx = i;
                continue;
            }

            if(numstr[i] < maxNum){
                leftIdx = i;
                rightIdx = maxIdx;
            }
        }
        if(leftIdx == -1)return num;//num already in good place

        swap(numstr[leftIdx], numstr[rightIdx]);
        return stoi(numstr);
    }
};