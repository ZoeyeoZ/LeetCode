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
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        helper(root);
        return flag;
    }
    int helper(TreeNode* root){
        if (!root || !flag)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if (abs(l-r)>1){
            flag = false;
            return 0;
        }
        return max(l,r)+1;
    }
};