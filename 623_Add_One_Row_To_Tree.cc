/*
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 0 || depth == 1){
            TreeNode *NewRoot = new TreeNode(val);
            (depth? NewRoot->left: NewRoot->right) = root;
            return NewRoot;
        }
        if(root && depth >= 2){
            root->left = addOneRow(root->left, val, depth > 2? depth-1: 1);
            root->right = addOneRow(root->right, val, depth >2? depth -1: 0);
        }
        return root;
        
    }

};