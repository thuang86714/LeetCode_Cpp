/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
Input: root = [3,1,4,null,2], k = 1
Output: 1*/
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
//it's a binary search tree, all nodes in the left tree must be smaller than the root,
//all nodes in the right tree must be larger than the root
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/63673/4-lines-in-c/
//credit to Easoncyx
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return recur(root, k);
    }
private:
    int recur(TreeNode* root, int& k){//int'&' is crucial
        if(!root)return INT_MIN; //base case
        int l = recur(root->left, k);
        if (k==0)return l;
        else if (k==1){
            k--;
            return root->val;
        }else{
            k--;
            int r = recur(root->right, k);
            if (k==0)return r;
            else return INT_MIN;
        }
    }
};