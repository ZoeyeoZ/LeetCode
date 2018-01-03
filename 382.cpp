/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
O(n) space: iterating & store, return rand()%n;[faster]
O(1) space: if (rand()%i==0) choose it(possibility=1/i), i=1..n
*/
class Solution {
private:
	ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
    	int ans = head->val;
    	ListNode* p = head->next;
    	int i = 2;
    	while (p){
    		// random 0..i-1
    		if (rand()%i==0)
    			ans = p->val;
    		i++;
    		p = p->next;
    	}
    	return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */