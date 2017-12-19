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
	vector<int> ans;
	void helper(TreeNode* root, int level){
		if (!root)
			return;
		if (ans.size()<level)
			ans.push_back(root->val);
		helper(root->right,level+1);
		helper(root->left,level+1);
	}
    vector<int> rightSideView(TreeNode* root) {
    	helper(root,1);
    	return ans;        
    }
};