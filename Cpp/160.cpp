/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
k1*(a+c)+a = k2*(b+c)+b
*/
/*

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cA = headA, *cB = headB;
        while (cA!=cB){
        	cA = cA? cA->next:headA;
        	cB = cB? cB->next:headB;
        }
        return cA;
    }
};
*/

//a+c+b = b+c+a
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cA = headA, *cB = headB;
        while (cA!=cB){
        	cA = cA? cA->next:headB;
        	cB = cB? cB->next:headA;
        }
        return cA;
    }
};