/*
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.*/
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
    
    string smallestFromLeaf(TreeNode* root, string s = "") {
        s = string(1, 'a' + root->val) + s;
        return root->left == root->right? s: min(root->left? smallestFromLeaf(root->left, s):"|", root->right? smallestFromLeaf(root->right, s):"|");
        //root->left == root->right meaning both are nullptr
    }
};

class Solution{
    public:
    
    string smallestFromLeaf(TreeNode* root){
        set<string> st;//ordering in it
        post(root, "",st);
        return *st.begin();
    }

    void post(TreeNode* root, string s, set<string> &st){
        if(!root)return;
        s += string(1, root->val + 'a');
        if(root->left == root->right){
            string temp = s;
            reverse(temp.begin(), temp.end());
            st.insert(temp);
        }
        post(root->left, s, st);
        post(root->right, s, st);
    }
};