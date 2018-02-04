/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
binary search tree
in-order, LrR
*/
class Solution {
public:
	int ans = INT_MAX, v = -1;
    int getMinimumDifference(TreeNode* root) {
    	if (root->left)
    		getMinimumDifference(root->left);
    	if (v>=0)
    		ans = min (ans,root->val-v);
    	v = root->val;
    	if (root->right)
    		getMinimumDifference(root->right);
    	return ans;
    }
};