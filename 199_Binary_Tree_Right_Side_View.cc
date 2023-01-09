/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]*/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 1;
        recur(root, result, level);
        return result;
    }
private:
    void recur(TreeNode* root, vector<int>& result, int level){
        if(!root)return ;//as the base case;
        if (result.size() < level)result.push_back(root->val);//for each level, there could be only one value, credit to gavin5
        recur(root->right, result, level+1);
        recur(root->left, result, level+1);
    }
};