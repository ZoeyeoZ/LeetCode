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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	stack<int> s1,s2;
    	for (;l1;l1=l1->next)
    		s1.push(l1->val);
    	for (;l2;l2=l2->next)
    		s2.push(l2->val);

    	ListNode* ans = new ListNode(0);
    	for (int carry = 0; !s1.empty()||!s2.empty();){
    		if (!s1.empty()) 
    			carry += s1.top(), s1.pop();
    		if (!s2.empty()) 
    			carry += s2.top(), s2.pop();
    		ans->val = carry%10;
    		ListNode* p = new ListNode(carry/=10);
    		p->next = ans;
    		ans = p;
    	}
    	return ans->val? ans:ans->next;
    }
};

/*Reverse
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=Reverse(l1);l2=Reverse(l2);ListNode* res=NULL;int c=0;
        while(l1||l2||c==1)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(c==1)
                sum+=c;
            c=sum/10;
            ListNode* p=new ListNode(sum%10);
            p->next=res;res=p;
        }
        return res;
    }
private:
    ListNode* Reverse(ListNode* l)
    {
        if(!l->next)
            return l;
        ListNode* p=NULL,*q=l;
        while(l)
        {
            l=l->next;
            q->next=p;
            p=q;
            q=l;
        }
        return p;
    }
};
*/