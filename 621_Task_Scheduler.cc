/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.*/
class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)return tasks.size();
        unordered_map<char, int> count;
        int maxCount = 0;
        for(char task: tasks){
            count[task]++;
            maxCount = max(maxCount, count[task]);
        }
        int ans = (maxCount - 1)*(n + 1);
        for(auto e:count){
            if(e.second == maxCount)ans++;
        }
        return max((int)tasks.size(), ans);//If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.
    }
};