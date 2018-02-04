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
	ListNode* p;
	bool helper(ListNode* head){
		if (head==NULL)
			return true;
		bool isP = helper(head->next) && (p->val == head->val);
		p = p->next;
		return isP;
	}
    bool isPalindrome(ListNode* head) {
    	p = head;
    	return helper(head);
    }
};

/*
9ms

static ListNode* head = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        
        ListNode* slow=head, *fast = head, *prev = nullptr;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        
        while (head) {
            ListNode* nxt = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = nxt;
        }
        
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};*/