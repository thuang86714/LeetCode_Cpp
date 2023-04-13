/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front(); q.pop();
            if(current->left){
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right] = current;
                q.push(current->right);
            }
        }

        q.push(target);
        visited[target] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(level++ == k)break;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front(); q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent[current] && !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* current = q.front(); q.pop();
            result.emplace_back(current->val);
        }
        return result;
    }
};