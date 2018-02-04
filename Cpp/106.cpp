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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int l = inorder.size();
        if (l==0)
            return NULL;
        return helper(inorder, postorder, 0, l-1, 0, l-1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int lin, int rin, int lpost, int rpost){
        if (lpost>rpost)
            return NULL;
        TreeNode* root = new TreeNode(postorder[rpost]);
        int i;
        for (i=lin; i<=rin; i++)
            if (inorder[i]==postorder[rpost])
                break;
        root->left = helper(inorder, postorder, lin, i-1, lpost, lpost+i-lin-1);
        root->right = helper(inorder, postorder, i+1, rin, lpost+i-lin, rpost-1);
        return root;
    }
};