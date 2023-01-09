/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.*/
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        return recur(root, result);
    }
private:
    vector<int> recur(TreeNode* root, vector<int>& result){
        if(!root)return result;
        result.push_back(root->val);
        if (root->left)recur(root->left, result);
        if (root->right)recur(root->right, result);
        return result;
    }
};