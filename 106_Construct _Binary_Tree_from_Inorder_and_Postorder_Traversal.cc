/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of 
a binary tree and postorder is the postorder traversal of the same tree, construct and 
return the binary tree.
Example:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/
/*
as we Know Inorder Fallow --> Left_subtree => Root_Node => Right_subtree Traverse
ans   Postorder Fallow --> Left_subtree => Right_subtree =>Root_Node traverse
*/
//credit to suman_buie
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recur(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
private:
    TreeNode* recur(vector<int>& inorder, int x, int y, vector<int>& postorder, int a, int b){
        if (x > y || a > b)return NULL;
        TreeNode* root = new TreeNode(postorder[b]);
        int SI = x;
        while (postorder[b] != inorder[SI])SI++;
        root->left = recur(inorder, x, SI-1, postorder, a, a+(SI-x)-1);
        root->right = recur(inorder, SI+1, y,postorder, a+(SI-x), b-1);//y is already inorder.size()-1, no need to y-1
        return root;
    }
};
/*    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]


    1st Phase=>        
	                   1

                   /        \

                [4 2 5]   [6 3 7]       <= inorder array
                [4 5 2]   [6 7 3]       <= postorder array

Now we have new freash problem like need to make tree by using inorder = [4 2 5] && postorder =  [4 5 2] for left subtree 
AND inorder = [6 3 7] && postorder = [6 7 3] for right  subtree 
**now same process we need to do again and again  until One Of the array dose not got empty
Rest of the Process show in a diagram Form :)

    2nd Phase =>
                           1

                      /        \
                     2          3
                [4]    [5]   [6]   [7]       <= inorder array
                [4]    [5]   [6]   [7]       <= postorder array


3rd Phase =>  
	             1

               /    \
              2      3
 
            /  \    /  \             <==== Answer
 
           4    5  6    7 */