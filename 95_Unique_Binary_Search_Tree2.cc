/*
Given an integer n, return all the structurally unique BST's (binary search trees), 
which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
Example:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]*/
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
//credit to chn
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return recur(1, n);
    }
private:
    vector<TreeNode*> recur(int from, int to){
        vector<TreeNode*> result;
        if (from > to){
            result.push_back(0);//for lefttree every level of recursive, the first element must be 0
        }else if (from == to){
            result.push_back(new TreeNode(from));
        }else if (from < to){
            for (int i = from; i <= to; i++ ){
                vector<TreeNode*> leftTree = recur(from, i-1);
                vector<TreeNode*> rightTree = recur(i+1, to);
                for (int j = 0; j < leftTree.size(); j++){
                    for(int k = 0; k < rightTree.size(); k++){
                        TreeNode* root = new TreeNode(i);
                        root->left = leftTree[j];
                        root->right = rightTree[k];
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
};
/*
explaination:
Given a tree which n nodes, it has the follwing form:
(0)root(n-1)
(1)root(n-2)
(2)root(n-3)
where (x) denotes the trees with x nodes.

Now take n=3 for example. Given n=3, we have [1 2 3] in 
which each of them can be used as the tree root.

when root=1: [1 # 2 # 3]; [1 # 3 2];
when root=2: [2 1 3];
when root=3: (similar with the situations when root=1.)

Thus, if we write a recursive function who generates a group of trees in which 
the numbers range from f to t, we have to generate the left trees and right trees of 
each tree in the vector.*/