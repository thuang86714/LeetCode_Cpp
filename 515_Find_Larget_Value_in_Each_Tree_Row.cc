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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root)return result;
        recur(root, 0, result);
        return result;
    }
private:
    void recur(TreeNode* node, int cur_L, vector<int> &result){
        if(node == NULL)return;
        if(result.size() < cur_L+1){
            result.emplace_back(node->val);
        }else{
            if(result[cur_L] < node->val){
                result[cur_L] = node->val;
            }
        }
        recur(node->left, cur_L+1, result);
        recur(node->right, cur_L+1, result);
    }
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root)return result;
        recur(root, 0, result);
        return result;
    }
private:
    void recur(TreeNode* node, int cur_L, vector<int> &result){
        if(node == NULL)return;
        if((int)result.size()-1 < cur_L){//result.size() -1 would not work when result.size() == 0, because .size() would return an uint
            result.emplace_back(node->val);
        }else{
            if(result[cur_L] < node->val){
                result[cur_L] = node->val;
            }
        }
        recur(node->left, cur_L+1, result);
        recur(node->right, cur_L+1, result);
    }
};