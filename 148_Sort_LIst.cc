/*
Given the head of a linked list, return the list after sorting it in ascending order.
Example:
Input: head = [4,2,1,3]
Output: [1,2,3,4]*/
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
    ListNode* sortList(ListNode* head) {
        //we use turtle-hare Algorithm to find the mid of this linked list
        if(head == nullptr || head->next == nullptr)return head;//as the base case && check the size
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;//temp would be the non-null last node in first half linked-list
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;//mark as the end of the first-half linked list
        ListNode* L1 = sortList(head);//recursive call for first-half linked list
        ListNode* L2 = sortList(slow);//recursive call for second-half linked list
        return mergeList(L1, L2);
    }
private:
    ListNode* mergeList(ListNode* L1, ListNode* L2){
        //we assume the 0 < =|first-half.size()-second-half.size()| <=1
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;//dummy will stay still, cur would move along the way
        //remember we are building a ascending order linked list
        while(L1 != nullptr && L2 != nullptr){//this while loop we assume equal lenth
            if (L1->val <= L2->val){
                cur->next = L1;
                L1 = L1->next;
            }else{
                cur->next = L2;
                L2 = L2->next;
            }
            cur = cur->next;
        }
        //for unqual length linked list
        if(L1 != nullptr){
            cur->next = L1;
            L1 = L1->next;
        }
        if(L2 != nullptr){
            cur->next = L2;
            L2 = L2->next;
        }
        return dummy->next;
    }
};