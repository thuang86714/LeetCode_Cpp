"""
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
 take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have 
finished course 1. So it is impossible.
"""
#credit to jianchao-li
#https://leetcode.com/problems/course-schedule/solutions/58509/c-bfs-dfs/
#DFS+Recursive, we are going to have a hash map to record for every course, the pre-requiste of it.
"""
Take example1 for demo
HashMap
Course   Pre-Req
0          [1]
1          []
Time Complexity of this would be O(n+p), as p is the pre-req.
 And we are going to use set for possible Loop
"""
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #map each course to the pre-req list:
        preMap = {i:[] for i in range(numCourses)}
        for crs, pre in prerequisites:
            preMap[crs].append(pre)
        # visitSet = all courses along the curr DFS search
        visitSet = set()
        #the recursive function
        def dfs(crs):
            #there are two base case:1.no loop or 2.no pre-re
            if crs in visitSet:#there's a loop
                return False
            if preMap[crs] == []:#there's no pre-req
                return True
            
            visitSet.add(crs)
            for pre in preMap[crs]:
                if not dfs(pre): return False
            visitSet.remove(crs)
            preMap[crs] = []
            return True

        for crs in range(numCourses):
            if not dfs(crs): return False
        return True


