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
    void reorderList(ListNode* head) {
    	//find midle
    	if (!head || !head->next)
    		return;
    	ListNode* p1 = head, *p2 = head->next, *tmp;
    	while (p2 && p2->next){
    		p1 = p1->next;
    		p2 = p2->next->next;
    	}
    	//reverse the remain
    	p2 = p1->next;
    	p1->next = NULL;
    	p1 = p2->next;
    	p2->next = NULL;
    	while (p1){
    		tmp = p1->next;
    		p1->next = p2;
    		p2 = p1;
    		p1 = tmp;
    	}
    	//mearge
    	p1 = head;
    	while (p1&&p2){
    		tmp = p1->next;
    		p1->next = p2;
    		p1 = p2->next;
    		p2->next = tmp; 
    		p2 = p1;
    		p1 = tmp;
    	}
    	return;
    }
};