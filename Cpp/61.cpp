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
    ListNode* rotateRight(ListNode* head, int k) {
    	ListNode* p = head;
    	int l = 0;
    	while (p){
    		l ++;
    		p = p->next;
    	}
    	if (l==0)
    		return head;
    	k = k%l;
    	if (k==0)
    		return head;
    	k = l-k-1;
    	p = head;
    	while (k--)
    		p = p->next;
    	ListNode* pp = p->next;
    	while (pp->next)
    		pp = pp->next;
    	pp->next = head;
    	pp = p->next;
    	p->next = NULL;
    	return pp;

        
    }
};