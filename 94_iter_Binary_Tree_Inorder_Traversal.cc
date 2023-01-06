//credit to jainchao-li
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;//LIFO
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();//return the last element in the stack;
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;//all the nodes on left tree and root have been traversed, now the nodes on the right tree
        }
        return nodes;
    }
};