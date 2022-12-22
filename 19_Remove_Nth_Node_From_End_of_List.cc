/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]*/
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
//time complexity O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* left = &dummy;
        ListNode* right = &dummy;
        for (int i = 0; i < n; i++){//we avoid manually relocate the right pointer
            right = right->next;
        }
        while (right->next){
            left = left->next;
            right = right->next;
        }
        ListNode *to_be_deleted = left->next;//actually not necessary
        left->next = left->next->next;
    
        delete to_be_deleted;//good hygiene habit

        return dummy.next;
    }
    
};