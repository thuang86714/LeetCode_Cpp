//BFS
//credit to pankit
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;//FIFO
        q.push(root);
        q.push(NULL);//using NULL to mark this is the end of one level
        vector<int> temp;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(temp);
                temp.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                temp.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};