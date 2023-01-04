/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
Example:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]*/
//credit to hi-malik
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //basically divide and conquer;
        ListNode* smalldummy = new ListNode(0);
        ListNode* bigdummy = new ListNode(0);
        ListNode* smalltail = smalldummy;//just for now
        ListNode* bigtail = bigdummy; //likewise, just for now; eventuall bigtail->next = NULL;
        while(head){
            if (head->val < x){
                smalltail->next = head;
                smalltail = smalltail->next;
            }else{
                bigtail->next = head;
                bigtail = bigtail->next;
            }
            head = head->next;
        }
        //right now, we have 2 subset of nodes
        smalltail->next = bigdummy->next;//bigdummy_next is the first node in bigger node
        bigtail->next = NULL;
        return smalldummy->next;
    }
};