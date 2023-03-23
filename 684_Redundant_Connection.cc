/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
 */
//https://leetcode.com/problems/redundant-connection/solutions/1295887/easy-solution-w-explanation-all-possible-approaches-with-comments/
//https://youtu.be/FXWRE67PLL0
//credit to archit91 && Neetcode
class DBS{//Disjoint Subset Union
    vector<int> rank, par;
public:
    DBS(int n): par(n), rank(n){
        iota(par.begin(), par.end(), 0);//fill the vector with int, start from 0, interval =1
    }

    int find(int x){//find the parent of x + root compression.
        if(x == par[x])return x;//x is the root of itslef, which is the base case
        return par[x] = find(par[x]);//return par[x] && do path compression
    }

    bool Union(int x, int y){//Union with rank
        int x_par = find(x), y_par = find(y);
        if(x_par == y_par)return false;//if false, meaning the 2 vertices cannot be unioned since the new union would cause cycle
        //the following lines for rank comparison
        if(rank[x_par] > rank[y_par]){
            par[y_par] = par[x_par];
        }else if(rank[x_par] < rank[y_par]){
            par[x_par] = par[y_par];
        }else{//rank[x_par] == rank[y_par]
            par[x_par] = y_par;// same rank - join either to other and increment rank of final parent
            rank[y_par]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DBS ds(n + 1);
        //it's about cycle detection in connected graph
        //Union by rank && Find with path compression to detect cycle
        for(auto E:edges){
            if(!ds.Union(E[0], E[1]))return E;
        }
        return {};

    }
};