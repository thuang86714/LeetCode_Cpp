/*
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.*/
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
//https://leetcode.com/problems/distribute-coins-in-binary-tree/solutions/221939/c-with-picture-post-order-traversal/

class Solution {
public:
    int moves = 0;
    int distributeCoins(TreeNode* root) {
        count(root, moves);
        return moves;
    }

    int count(TreeNode* root, int &moves){
        if(!root)return 0;
        int left = count(root->left, moves);
        int right = count(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;// -1 is for itself
    }
};