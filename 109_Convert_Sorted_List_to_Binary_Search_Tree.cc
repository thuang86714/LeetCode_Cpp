/*
Given the head of a singly linked list where elements are sorted in ascending order, 
convert it to a height-balanced binary search tree.
 Example:
 Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5],
 which represents the shown height balanced BST.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return recur(head, NULL);
    }
private:
    TreeNode* recur(ListNode* head, ListNode* tail){
        if (head == tail)return nullptr;//there's no node in the linked list;
        if(head->next == tail){
            TreeNode* root = new TreeNode(head->val);
            return root;//there's only one node in the linked list;
        }
        ListNode *mid = head, *temp = head;
        while(temp != tail && temp->next != tail){
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = recur(head, mid);
        root->right = recur(mid->next, tail);
        return root;
    }
};