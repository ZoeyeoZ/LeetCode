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
    	ListNode* phead = new ListNode(0);
    	ListNode* p = phead;
    	ListNode* pre = head;
    	ListNode* cur;
    	cout <<head->val<<endl;
    	if (head->next)
    		cur = head->next;
    	else
    		return head;
    	while (cur){
    		cout << "aaaa"<<cur->val<<endl;
    		cout << "bbbb"<<pre->val<<endl;
    		if (cur->val!=pre->val){
    			cout << pre->val<<endl;
    			p->next = pre;
    			p = p->next;
    			pre = cur;
    			cur = cur->next;
    		}
    		else{
    			while (cur && cur->val==pre->val)
    				cur = cur->next;
    			pre = cur;
    			cur = pre ? pre->next:NULL;
    		}
    	}
    	if (pre)
    		p->next = pre;
    	else p->next = NULL;
    	return phead->next;
        
    }
};

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode* cur=head;
        ListNode* prev=newHead;
        while(cur!=NULL&&cur->next!=NULL)
        {
            if(cur->val==cur->next->val)
            {
                
                while(cur->next!=NULL&&cur->val==cur->next->val)
                {
                    cur=cur->next;
                }
                cur=cur->next;
                prev->next=cur; // find the one who is diff thran next;
                continue;
            }
            
            prev=prev->next;
            if(cur!=NULL)
                cur=cur->next;
            
        }
        return newHead->next;
    }
};
*/