/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will 
fit in a 32-bit integer.

A leaf node is a node with no children.*/
//credit to archit91
/*
We wiil use dfs
We can intuitively see that a DFS solution will fit well here since we traverse from root to 
leaf in a DFS traversal and thus we can use it to form number represented by each root-to-leaf path. 
In DFS traversal -

We start at the root with current number cur = 0.
Every time, the current node's digit will be appended to cur from root to leaf and we recurse 
for left and right child.
If we reach a leaf node (a node not having any left or right child), we have formed the 
complete root-to-leaf number. We will then add this number cur to the overall sum.*/
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* root, int cur){
        if(!root)return 0;
        cur = cur*10 + root->val;
        if (!cur->left && !cur->right)return cur;
        return dfs(root->left, cur)+dfs(root->right, cur);
    }
};
/*
Time Complexity : O(N), where N is the number of nodes in the tree. We are doing a standard
 DFS traversal which takes O(N) time
Space Complexity : O(H), where H is the maximum depth of tree. This space is required for 
implicit recursive stack space. In the worst case, the tree maybe skewed and H = N in which
 case space required is equal to O(N).*/