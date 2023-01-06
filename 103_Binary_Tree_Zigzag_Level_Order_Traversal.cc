/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//the idea is very close to 102--BFS, but in here we use a bool to indicate ZigZag
//credit to StevenCooks; if from right to left,  
//the ith node in current queue should be placed in (queue.size() - 1 - i)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)return vector<vector<int> > ();
        queue<TreeNode*> q;
        q.push(root);
        bool isLefttoRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);//pre-allocate size is important because we play with the index number of this vector
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (isLefttoRight)? i: size-1-i;
                temp[index] = node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            isLefttoRight = !isLefttoRight;
            result.push_back(temp);
        }
        return result;
    }
};