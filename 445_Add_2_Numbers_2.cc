/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = 0, l2_len = 0, carry = 0, sum;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        while(curr1){curr1 = curr1->next; l1_len++;}
        while(curr2){curr2 = curr2->next; l2_len++;}
        curr1 = l1; curr2 = l2;
        while(l1_len > 0 && l2_len > 0){
            sum = 0;
            if(l1_len >= l2_len){sum += curr1->val; curr1 = curr1->next; l1_len--;}
            if(l2_len > l1_len){sum += curr2->val; curr2 = curr2->next; l2_len--;}
            res = addtoFront(sum, res);//here, sum could be a 2-digit int, carry would be handled later
        }
        curr1 = res; res = NULL;
        while(curr1){//here we are handling the carry
            curr1->val += carry;//the initial value of carry is 0
            carry = curr1->val/10;
            res = addtoFront(curr1->val%10, res);//res is now NULL &&here we are using O(n) extra space
            curr1 = curr1->next;
        }
        if(carry)res = addtoFront(carry,res);
        return res;
    }
private:
    ListNode* addtoFront(int digit, ListNode* head){
        ListNode *temp = new ListNode(digit);
        temp->next = head;
        return temp;
    }
};