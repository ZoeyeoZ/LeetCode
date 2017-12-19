//Merge k Sorted Lists
#include <queue>
struct compare{
	bool operator()(const ListNode* l1, const ListNode* l2){
		return l1->val > l2->val;
	}
};
class Solution{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists){
		priority_queue<ListNode*, vector<ListNode*>, compare> q;
		//for (ListNode* l:lists)
		for (auto l:lists)
			if (l)
				q.push(l);
		if (q.empty())
			return NULL;
		ListNode* ans = q.top();
		ListNode* h = ans;
		q.pop();
		if (h->next) q.push(h->next);
		while (!q.empty()){
			h->next = q.top();
			q.pop();
			h = h->next;
			if (h->next) q.push(h->next);
		}
		return ans;
	}
};

/*
时间复杂度： 
PriorityQueue的peek()和element操作是常数时间，
add(), offer(), 无参数的remove()以及poll()方法的时间复杂度都是O(log n)
*/