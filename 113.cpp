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
	vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> tmp;
    	helper(tmp, root, sum);
    	return ans;
    }
    void helper(vector<int> tmp, TreeNode* root, int sum){
    	if (!root)
    		return;
    	tmp.push_back(root->val);
    	if (sum==root->val && !root->left && !root->right)
    		ans.push_back(tmp);
    	else {
	    	helper(tmp,root->left,sum-root->val);
	    	helper(tmp,root->right,sum-root->val);
	    }
    }
};