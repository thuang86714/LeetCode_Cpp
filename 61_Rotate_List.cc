/*
Given the head of a linked list, rotate the list to the right by k places.
Example:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]*/
//credit to Neetcode
class Solution{
public: 
 ListNode *rotateRight(ListNode *head, int k) 
     {
        if(head == NULL || head->next == NULL||k==0) return head;
        
        ListNode* tail = head;
        ListNode* newhead;
        ListNode* cur;
        int size = 1;
        while (tail->next != NULL){
            size++;
            tail = tail->next;
        }
        k = k % size;
        if (k == 0)return head;
        cur = head;
        for (int i = 0; i < size-k-1 ; i++){//take size-k-1 steps to move from the olde head 
        //to pivot point, using "<" is because i start from 0
            cur = cur->next;
        }
        newhead = cur->next;
        cur->next=NULL;
        tail->next=head;
        return newhead;
    }
};