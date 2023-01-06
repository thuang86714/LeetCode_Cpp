/*
Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. 
A leaf is a node with no children.
Example:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22*/
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
//credit to myself and jianchao-li
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        recur(root, targetSum, result, temp);
        return result;
    }
private:
    void recur(TreeNode* root, int targetSum, vector<vector<int>>& result, vector<int> temp){
        if(!root)return;
        temp.push_back(root->val);
        if(!(root->left) && !(root->right) && (root->val)-targetSum == 0){//the base case
            result.push_back(temp);
        }
        recur(root->left, targetSum - (root->val), result, temp);
        recur(root->right, targetSum - (root->val), result, temp);
        temp.pop_back();
    }
};