/*
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.
/*
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
//https://leetcode.com/problems/find-duplicate-subtrees/solutions/106055/c-java-clean-code-with-explanation/
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> result;
        serialize(root, map);
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second.size() > 1)result.push_back(it->second[0]);
        }
        return result;
    }
private:
    string serialize(TreeNode *node, unordered_map<string, vector<TreeNode*>>& map){
        if(!node)return "";
        string s = "(" + serialize(node->left, map) + to_string(node->val)+ serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};