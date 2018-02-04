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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head)
    		return head;
    	ListNode* cur = head;
    	while (cur && cur->next){
    		int tmp = cur->val;
    		while (cur && cur->next && tmp==cur->next->val)
    			cur->next = cur->next->next;
    		cur = cur->next;
    	}

    	return head;
        
    }
};