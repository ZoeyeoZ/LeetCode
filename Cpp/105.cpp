/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// pre:rLR, in:LrR
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int l = preorder.size();
        if (l==0)
        	return NULL;
        return helper(preorder, inorder, 0, l-1, 0, l-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int lpre, int rpre, int lin, int rin){
    	if (lpre>rpre)
    		return NULL;
    	TreeNode* root = new TreeNode(preorder[lpre]);
    	int i;
    	for (i=lin; i<=rin; i++)
    		if (inorder[i]==preorder[lpre])
    			break;

        root->left = helper(preorder, inorder, lpre+1, lpre+i-lin, lin, i-1);
        root->right = helper(preorder, inorder, lpre+i-lin+1, rpre, i+1, rin);
        return root;
    }
};