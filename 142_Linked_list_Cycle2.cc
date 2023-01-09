/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, 
return null.

There is a cycle in a linked list if there is some node in the list that can be reached again 
by continuously following the next pointer. Internally, pos is used to denote the index of the 
node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle.
 Note that pos is not passed as a parameter.

Do not modify the linked list.*/
//credit to ngcl
/*
Alogrithm Description:
Step 1: Determine whether there is a cycle

1.1) Using a slow pointer that move forward 1 step each time

1.2) Using a fast pointer that move forward 2 steps each time

1.3) If the slow pointer and fast pointer both point to the same location after 
several moving steps, there is a cycle;

1.4) Otherwise, if (fast->next == NULL || fast->next->next == NULL), there has no cycle.

Step 2: If there is a cycle, return the entry location of the cycle

2.1) L1 is defined as the distance between the head point and entry point

2.2) L2 is defined as the distance between the entry point and the meeting point

2.3) C is defined as the length of the cycle

2.4) n is defined as the travel times of the fast pointer around the cycle When the first
 encounter of the slow pointer and the fast pointer

According to the definition of L1, L2 and C, we can obtain:

the total distance of the slow pointer traveled when encounter is L1 + L2

the total distance of the fast pointer traveled when encounter is L1 + L2 + n * C

Because the total distance the fast pointer traveled is twice as the slow pointer, Thus:

2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)*

It can be concluded that the distance between the head location and entry location is equal to
 the distance between the meeting location and the entry location along the direction of forward 
 movement.

So, when the slow pointer and the fast pointer encounter in the cycle, we can define a pointer 
"entry" that point to the head, this "entry" pointer moves one step each time so as the slow
 pointer. When this "entry" pointer and the slow pointer both point to the same location, 
 this location is the node where the cycle begins.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow ==fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};