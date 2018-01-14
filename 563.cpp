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
	int helper(TreeNode* root, int& ans){
		if (!root)
			return 0;
		int l = helper(root->left, ans);
		int r = helper(root->right, ans);
		ans += abs(l-r);
		return l+r+root->val;
	}
    int findTilt(TreeNode* root) {
        int ans = 0;
       	helper(root, ans);
       	return ans;
    }
};