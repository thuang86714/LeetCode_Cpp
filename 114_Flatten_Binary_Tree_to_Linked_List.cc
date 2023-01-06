/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points 
to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]*/
//credit to sgallivan
/*Recursive:
Time Complexity: O(N) where N is the number of nodes in the binary tree
Space Complexity: O(N) for the recursion stack, which is as long as the 
maximum depth of the binary tree, which can go up to N*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root) revPreOrder(root);
    }
private:
    TreeNode* head = nullptr;
    void revPreOrder(TreeNode* node) {
        if (node->right) revPreOrder(node->right);
        if (node->left) revPreOrder(node->left);
        node->left = nullptr, node->right = head, head = node;
    }
};