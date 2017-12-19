//Reverse Nodes in k-Group
class Solution{
public:
	ListNode* reverseKGroup(ListNode* head, int k){
		ListNode* l = new ListNode(0);
		l->next = head;
		ListNode* h = l;
		int n = 0;
		while ((h = h->next))
			n++;
		h = l;
		ListNode* p, * q;
		while (n>=k){
			p = h->next;
			for (int i=0; i<k-1; i++){
				q = p->next->next;
				p->next->next = h->next;
				h->next = p->next;
				p->next = q;
			}
			h = p;
			n -=k ;

		} 
		return l->next;
	}
};