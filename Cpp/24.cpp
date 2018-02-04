//Swap Nodes in Paris
class Solution{
public:
	ListNode* swapPairs(ListNode* head){
		ListNode* l = new ListNode(0);
		l->next = head;
		ListNode* h = l;

		ListNode* p;
		while ((h->next)&&(h->next->next)){
			p = h->next; //1
			h->next = h->next->next; //0-2
			p->next = h->next->next; //1-3
			h->next->next = p; //0-2-1-3			
			h = h->next->next;
		}
		return l->next;
	}
};