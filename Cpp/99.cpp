// find the one 
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
	TreeNode* E1 = NULL;
	TreeNode* E2 = NULL;
	// last  largest num
	TreeNode* L = new TreeNode(INT_MIN);
    vector<int> ans;
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(E1->val,E2->val);
        
    }
    void helper(TreeNode* root){
        if (!root)
            return;
        helper(root->left);
        if (!E1 && L->val >= root->val)
        	E1 = L;
        if (E1 && root->val <= L->val)
        	E2 = root;
        L = root;
        helper(root->right);
    }
};