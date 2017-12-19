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
    ListNode* sortList(ListNode* head) {
    	int n = 0;
    	ListNode* p = head;
    	while (p){
    		p = p->next;
    		n++;
    	}
    	ListNode* newH = new ListNode(0);
    	newH->next = head;
    	int step = 1;
    	ListNode* p1,*p2,*p3,*pre;
    	while (step<n){
    		p1 = newH->next;
    		pre = newH;
    		while (p1){
	    		// split into step number
	    		p = p1;
	    		for (int i=1;i<step && p;i++)
	    			p = p->next;
	    		if (!p)
	    			p2 = NULL;
	    		else {
	    			p2 = p->next;
	    			p->next = NULL;
	    		}
	    		p = p2;
	    		for (int i=1;i<step && p;i++)
	    			p = p->next;
	    		if (!p)
	    			p3 = NULL;
	    		else {
	    			p3 = p->next;
	    			p->next = NULL;
	    		}


	    		//merge
	    		while (p1&&p2){
	    			if (p1->val>p2->val){
	    				pre->next = p2;
	    				pre = p2;
	    				p2 = p2->next;
	    			}
	    			else {
	    				pre->next = p1;
	    				pre = p1;
	    				p1 = p1->next;
	    			}
	    		}
	    		pre->next = (p1?p1:p2);
	    		while (pre->next)
	    			pre = pre->next;
	    		pre->next = p3;
	    		p1 = p3;


	    	}
    		step<<=1;
    	}
    	return newH->next;      
    }
};