/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	//coey l1: A->newA->B->newB->...
    	if (!head)
    		return NULL;
    	RandomListNode* newH, *l1 = head, *l2;
    	for (l1 = head; l1!=NULL; l1=l1->next->next){
    		l2 = new RandomListNode(l1->label);
    		l2->next = l1->next;
    		l1->next = l2;
    	}
    	//coey new random node
    	for (l1 = head; l1!=NULL; l1=l1->next->next)
    		if (l1->random)
    			l1->next->random = l1->random->next;
    	//split into 2
    	newH = head->next;
    	for (l1 = head; l1!=NULL; l1=l1->next){
    		l2 = l1->next;
    		l1->next = l1->next->next;
    		if (l2->next)
	    		l2->next = l2->next->next;
    	}
    	return newH;
    }
};