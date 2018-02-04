/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* p;
    TreeNode* sortedListToBST(ListNode* head) {
    	int l = 0;
    	p = head;
    	while (head){
    		head = head->next;
    		l++;
    	}
    	return helper(l);
    }
    TreeNode* helper(int l){
    	if (l==0)
    		return NULL;
    	TreeNode* root = new TreeNode(0);
    	root->left = helper(l/2);
    	root->val = p->val;
    	p = p->next;
    	root->right = helper(l-l/2-1);
    	return root;
    }
};