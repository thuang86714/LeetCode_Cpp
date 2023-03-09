/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        if(n==2)return {0,1};
        vector<vector<int>> G(n);
        for (auto e:edges){
            G[e[1]].push_back(e[0]);
            G[e[0]].push_back(e[1]);
        }
        vector<int> leaves, Newleaves, indegree;
        for(int i = 0; i < n; i++){
            if(G[i].size() == 1){
                leaves.push_back(i);
            }
            indegree.push_back(G[i].size());
        }
        while(n>2){
            for(auto leaf:leaves){
                for(auto adj :G[leaf]){
                    if(--indegree[adj]==1){
                        Newleaves.push_back(adj);
                    }
                }
            }
            n -= leaves.size();
            leaves = move(Newleaves);
        }
        return leaves;
    }
};
//Time and space complexity are both O(n)
//https://leetcode.com/problems/minimum-height-trees/solutions/1631179/c-python-3-simple-solution-w-explanation-brute-force-2x-dfs-remove-leaves-w-bfs/
//https://leetcode.com/problems/minimum-height-trees/solutions/827284/c-99-tc-with-explanation-using-bfs-top-sort/