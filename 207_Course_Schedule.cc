//credit to dw70
/*
All the courses can be taken if we can come up with a topological sorting of the courses that
 includes every single course. However, the input provided in the form of an array of edges is
  not very easy to work with, so we first convert it to an adjacency list representation.
   Then, we simply run a standard topological sort on the graph. We first loop through 
   the adjacency list to get all the courses with no prerequisites (nodes of indegree 0), 
   which will be the starting points of the topological ordering. Then, for each of those nodes, 
   we "remove" the node from the graph by decrementing the indegree of all courses that it is a
    prerequisite for, and if any course ends up having an updated indegree of 0, then we add it 
    to a queue of courses to process next and repeat the process with.

Every time we "remove" a course from the graph, we decrement the number of courses to take by 1. 
Thus, at the end, we can simply check if the number of courses to take is 0: if so,
 then that means we were able to take all the courses; otherwise, we were not able to and
  so false is returned.

Traversing all the edges takes O(E) and then running topological sort takes O(V+E), 
so this solution takes O(V+E) overall. We also represent the input as an adjacency list, 
which takes up O(V+E) space.*/
class Solution {
    //BFS+indegree
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;//those nodes in this queus can be later removed
        for (int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }

        for (int i = 0; i < degree.size(); i++){
            if (degree[i] ==0){
                zeroDegree.push(i);
                numCourses--;
            }
        }

        while(!zeroDegree.empty()){
            int node = zeroDegree.front();
            zeroDegree.pop();
            for (int i = 0; i < graph[node].size(); i++){
                int Connetednode = graph[node][i];
                degree[Connetednode]--;//remove the int variable node
                if (degree[Connetednode]==0){
                    zeroDegree.push(Connetednode);
                    numCourses--;
                }
            }
        }
        return numCourses == 0 ;
        
    }

    
};