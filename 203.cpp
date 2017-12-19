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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newH = new ListNode(0);
        newH->next = head;
        head = newH;
        while (head){
            while (head && head->next && head->next->val!=val)
                head = head->next;
            if (head->next)
                head->next = head->next->next;
            else
                head->next = NULL;
            if (head->next){
                if (head->next->val!=val)
                    head = head->next;
            }
            else 
                break;
        }
        return newH->next;
    }
};