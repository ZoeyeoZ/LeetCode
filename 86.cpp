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
    ListNode* partition(ListNode* head, int x) {
    	ListNode* Lhead = new ListNode(0);
    	ListNode* Shead = new ListNode(0);
    	ListNode* l = Lhead, *s = Shead;
    	while (head){
    		ListNode* &tmp = head->val < x ? s:l;
    		tmp->next = head;
    		tmp = tmp->next;
    		head = head->next;
    	}
    	l->next = NULL;
    	s->next = Lhead->next;
    	return Shead->next;
        
    }
};