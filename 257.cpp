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
	vector<string> ans;
	void helper(string s, TreeNode* root){
		if (root->left == NULL && root->right == NULL){
			ans.push_back(s+"->"+to_string(root->val));
			return;
		}
		if (root->left)
			helper(s+"->"+to_string(root->val),root->left);
		if (root->right)
			helper(s+"->"+to_string(root->val),root->right);
		return;

	};
    vector<string> binaryTreePaths(TreeNode* root) {
    	if (root==NULL)
    		return {};
    	if (root->left == NULL && root->right == NULL)
    		return {to_string(root->val)};
    	if (root->left)
    		helper(to_string(root->val),root->left);
    	if (root->right)
    		helper(to_string(root->val),root->right);
    	return ans;
        
    }
};