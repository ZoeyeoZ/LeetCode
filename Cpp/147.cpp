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
    ListNode* insertionSortList(ListNode* head) {
    	if (!head)
    		return head;
    	ListNode* newH = new ListNode(0);
    	ListNode* p = newH;
        ListNode* next;
    	while (head){
            next = head->next;
            while (p->next && p->next->val<head->val)
                p = p->next;
            head->next = p->next;
            p->next = head;
            p = newH;
            head = next;
    	}
        return newH->next;
    }
};