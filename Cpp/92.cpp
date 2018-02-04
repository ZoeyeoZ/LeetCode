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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;
        int i=m-1;
        while (pre && i--)
            pre = pre->next;
        ListNode* cur = pre->next;
        i = n-m;
        while (i--) {
            ListNode* move = cur->next; 
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return newhead->next;
        
    }
};