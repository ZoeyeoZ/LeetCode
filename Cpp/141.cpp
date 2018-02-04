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
    bool hasCycle(ListNode *head) {
    	ListNode* p = head, *pre;
    	while (p && p->next){
    		if (p->next == head)
    			return true;
    		pre = p;
    		p = p->next;
    		pre->next = head;
    	}
    	return false;
    }
};

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *oneStep = head, *twoSteps = head;
        while (twoSteps != nullptr) {
            oneStep = oneStep->next;
            twoSteps = twoSteps->next != nullptr ? twoSteps->next->next : nullptr;
            if (twoSteps != nullptr && twoSteps == oneStep) {
                return true;
            }
        }
        return false;
    }
};
*/