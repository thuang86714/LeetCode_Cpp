/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Example:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), 
your function should populate each next pointer to point to its next right node, 
just like in Figure B. The serialized output is in level order as connected by the next pointers, 
with '#' signifying the end of each level.*/
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
//very similar to 116, the significant difference is that, this time, it's not a "perfect" binary tree
//hence, the DFS approach used in 116 may not work this time
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* rightnode = nullptr;//every new while loop, we get a new q.size 
            for(int i = q.size(); i; i--){
                auto cur = q.front();
                q.pop();
                cur->next = rightnode;
                rightnode = cur;
                if(cur->right){
                    q.push(cur->right);
                }
                if(cur->left){//since it's no longer a "perfect" binary tree, one extra check is necessary
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};