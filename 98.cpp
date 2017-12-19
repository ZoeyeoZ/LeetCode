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
    bool isValidBST(TreeNode* root) {
    	return helper(root, NULL, NULL);
    }
    bool helper(TreeNode* root, TreeNode* minnode, TreeNode* maxnode){
    	if (!root)
    		return true;
    	if (minnode && root->val <= minnode->val || maxnode && root->val >= maxnode->val)
    		return false;
    	return helper(root->left, minnode, root) && helper(root->right, root, maxnode);
    }
};