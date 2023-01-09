/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
Example:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).*/
//https://leetcode.com/problems/clone-graph/solutions/1792834/c-easy-explanation-dfs/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//credit to Abhay_Rautela

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        if (!node)return nullptr;
        if (node->neighbors.size()==0){////if only one node present no neighbors
            Node* root = new Node(node->val);
            return root;
        }
        return dfs(node, mp);
    }
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp){// pass by reference is up-most crucial
        vector<Node*> neighbor;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for (auto it:node->neighbors){
            if(mp.find(it) != mp.end()){//meanning this node is traversed and cloned
                neighbor.push_back(mp[it]);
            }else{
                neighbor.push_back(dfs(it,mp));
            }
        }
        clone->neighbors = neighbor;
        return clone;

    }
};