//Merge Two Sorted Lists
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
		ListNode* l = new ListNode(0);
		ListNode* h =l;
		while (l1&&l2)
			if (l1->val < l2->val){
				h->next = l1;
				l1 = l1->next;
				h = h->next;
			}
			else {
				h->next = l2;
				l2 = l2->next;
				h = h->next;
			}
		h->next = l1 ? l1 : l2;
		return l->next;
	}
};