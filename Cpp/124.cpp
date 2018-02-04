/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 
class Solution {
public:
	int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
    	//return max(l,r)+root. ans = l,r,l+root+r
    	ans = max(ans, helper(root));
    	return ans;
    }
    int helper(TreeNode* root){
    	if (!root)
    		return INT_MIN;
        if (!root->left)
            if (!root->right){
                ans = max(ans,root->val);
                return root->val;
            }
            else{
                int r = helper(root->right);
                ans = max(ans,r);
                return max(root->val,r+root->val);
            }
        else
            if (!root->right){
                int l = helper(root->left);
                ans = max(ans,l);
                return max(root->val,l+root->val);
            }
            else{
                int l = helper(root->left);
                int r = helper(root->right);
                int tmp = max(l,r);
                ans = max(max(tmp,l+r+root->val),ans);
                return max(root->val,tmp+root->val);
            }
    }
};