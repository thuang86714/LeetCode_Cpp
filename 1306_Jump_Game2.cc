/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3*/
//https://leetcode.com/problems/jump-game-iii/solutions/1619031/c-python-simple-solution-w-explanation-dfs-bfs-traversals/
class Solution{
public:
    bool canReach(vector<int>&A, int cur){
        if(cur<0 || cur>= A.size() || A[cur] < 0)return false;
        A[cur] *= -1;
        return !A[cur] || canReach(A, cur + A[cur]) ||canReach(A, cur - A[cur]);// return true if A[cur] == 0 or recurse for both possible jumps
    }
};

class Solution{
public:
    bool canReach(vector<int>&a, int cur){
        queue<int> q;
        q.push(cur);
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(a[cur]==0)return true;
            if(a[cur] < 0)continue;
            if(cur+a[cur] < a.size())q.push(cur+a[cur]);
            if(cur-a[cur]>=0) q.push(cur-a[cur]);
            a[cur] *= -1;

        }
        return false;
    }
};

