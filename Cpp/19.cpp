//Remove Nth Bode From End of List
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n){
		ListNode *l1 = head, **l2 = &head;
		for (int i=0; i<n-1; i++)
			l1 = l1->next;
		while (l1->next){
			l1 = l1->next;
			l2 = &((*l2)->next);
		}
		(*l2) = (*l2)->next;
		return head;
	}
};