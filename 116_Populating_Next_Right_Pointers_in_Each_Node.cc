/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Example:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A),
 your function should populate each next pointer to point to its next right node, 
 just like in Figure B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.*/
//credit to arcit91
/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/solutions/1654181/c-python-java-simple-solution-w-images-explanation-bfs-dfs-o-1-optimized-bfs/
We use BFS to solve problem:
Time Complexity : O(N), where N is the number of nodes in the given tree.
 We only traverse the tree once using BFS which requires O(N).
Space Complexity : O(W) = O(N), where W is the width of given tree. 
This is required to store the nodes in queue. Since the given tree is a perfect binary tree, 
its width is given as W = (N+1)/2 ≈ O(N)*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {//in this right-to-left bfs solution, we will use queue
    if(!root)return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* rightnode = nullptr;//every time enter a new while loop, meaning entering the a lower level,
            // we need a new nullptr as the right most node
            for(int i = q.size(); i ; i--){//here the statement2 in for loop condition means i > 0
                auto cur = q.front();
                q.pop();
                cur->next = rightnode;
                rightnode = cur;
                if(cur->right){
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        //when we exit while loop, meaning all nodes have been traversed
        return root;
    }
};