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
	int depth(TreeNode* root){
		if (!root)
			return 0;
		else
			return 1+max(depth(root->left),depth(root->right));
	}
    int diameterOfBinaryTree(TreeNode* root) {
    	if (!root)
    		return 0;
    	else
    		return max(depth(root->left)+depth(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));        
    }
};
/*
6
class Solution {
public:
    int _recurse(TreeNode* root, int &ans) {
        if (!root->left && !root->right) {
            return 0;
        }
        
        int left = 0, right = 0;
        if (root->left) left = _recurse(root->left, ans) + 1;
        if (root->right) right = _recurse(root->right, ans) + 1;
        
        if (left + right > ans) {
            ans = left + right;
        }
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        _recurse(root, ans);
        return ans;
    }
};
*/