/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
Input: root = [1,2,3,4,5,6]
Output: 6*/
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
//credit to victorlee
//https://leetcode.com/problems/count-complete-tree-nodes/solutions/61953/easy-short-c-recursive-solution/
//time complexity O(logN*logN)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)return 0;
        int LeftHeight = 0, RightHeight = 0;
        TreeNode* l = root;
        TreeNode* r = root;

        while(l){
            LeftHeight++;
            l = l->left;
        }

        while(r){
            RightHeight++;
            r = r->right;
        }

        if(LeftHeight == RightHeight){
            return pow(2, LeftHeight)-1;
        }else{
            return 1 + countNodes(root->left)+ countNodes(root->right);
        }
    }
};