/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*//*
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?

head->chead: L1;
chead->1setp: L2;
=> 	1setp: L1+L2+k1C
 	2step: L1+L2+k2C
=>	L1+L2+k2C = 2(L1+L2+k1C)
=>	L1 = (2k1-k2)C - L2
	   = kC + (C-L2)	

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *oneStep = head, *twoSteps = head, *st = head;
        while (twoSteps != nullptr) {
            oneStep = oneStep->next;
            twoSteps = twoSteps->next != nullptr ? twoSteps->next->next : nullptr;
            if (twoSteps != nullptr && twoSteps == oneStep) {
            	while (st!=oneStep){
            		oneStep = oneStep->next;
            		st = st->next;
            	}
                return st;
            }
        }
        return NULL;
    }
};