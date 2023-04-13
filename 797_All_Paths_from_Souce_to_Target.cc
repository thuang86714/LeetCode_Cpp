/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

*/
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(graph, result, temp, 0);
        return result;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>> &result, vector<int> &temp, int cur){
        temp.push_back(cur);
        if(cur == graph.size() - 1){
            result.push_back(temp);
        }else{
            for(auto it:graph[cur]){
                dfs(graph, result,temp, it);
            }
        }
        temp.pop_back();
    }
};