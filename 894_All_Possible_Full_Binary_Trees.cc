/*
Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.*/
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
//https://leetcode.com/problems/all-possible-full-binary-trees/solutions/167402/c-c-java-python-recursive-and-iterative-solutions-doesn-t-create-frankenstein-trees/
//credit to ChrisTrompf
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
    TreeNode* clone(TreeNode* root){
        TreeNode* new_root = new TreeNode(0);
        new_root->left = (root->left)? clone(root->left):nullptr;
        new_root->right = (root->right)? clone(root->right):nullptr;
        return new_root;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
        if(n == 1){
            result.emplace_back(new TreeNode(0));
        }
        if(n%2){
            for(int i = 2; i < n; i+=2){
                auto left = allPossibleFBT(i - 1);
                auto right = allPossibleFBT(n - i);
                for(int l_idx = 0; l_idx < left.size(); l_idx++){
                    for(int r_idx = 0; r_idx < right.size(); r_idx++){
                        result.emplace_back(new TreeNode(0));
                        result.back()->left = (r_idx == right.size() - 1)? left[l_idx]:clone(left[l_idx]);
                        result.back()->right = (l_idx == left.size() - 1)? right[r_idx]:clone(right[r_idx]);
                    }
                }
            } 
        }
        return result;
    }
};
/*
Recursive solutions
Rather that build up from 1 to N, to recurse we build up an answer by working backwards from N to 1. The problem is that for any root there could be multiple ways of filling out the left branch and multiple ways of filling out the right branch, with each selection being a new unique tree. For example, if N is 11 and we've chosen the middle node as our root, there are 5 nodes to use on each branch. 5 nodes can form a full BST in two ways. We therefore have 2 possible left branches and 2 possible right branches or a total of 2 x 2 = 4 posibilites.

Each left branch posibility is used twice (one for each right branch choice), but we only have a single copy of it, so we can either doubly linked to it and end up with Frankenstein trees or clone it. The trick is that we don't want always clone it, because we will end up hanging copy that is never deallocated and hence memory leak. The solution is to clone for each use except the last one wheer we will actually use it.*/