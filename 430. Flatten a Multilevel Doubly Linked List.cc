/*
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        while(temp){
            if(temp->child){
                Node *temp2 = temp->child;
                Node *front = temp->next;
                temp->next = temp2;
                temp->child = NULL;
                temp2->prev = temp;
                while(temp2->next){
                    temp2 = temp2->next;
                }
                if(front){
                    front->prev = temp2;
                    temp2->next = front;
                }
                temp = temp->next;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};