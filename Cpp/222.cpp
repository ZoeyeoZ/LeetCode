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
    int countNodes(TreeNode* root) {
    	if (!root)
    		return 0;
    	int h = 0;
    	TreeNode* p = root;
    	while (p->left){
    		h++;
    		p = p->left;
    	}
    	int l = 0, ans = (1<<h)-1, level = 1;
    	while (l<ans){
    		int m = (ans+l)/2;
    		p = root->left;
    		for (int i=level; i<h; ++i, p=p->right);
            if (p) {
                l = m+1;
                root = root->right;
            } else {
                ans = m;
                root = root->left;
            }
            ++level;
    	}
    	return (1<<h) + (root?0:-1) + ans;
    }
};
/*
class Solution {
public:
	int height(TreeNode* root){
		return root==null? -1 : 1+height(root->left);
	}
    int countNodes(TreeNode* root) {
    	int h =height(root);
    	return h<0? 0:
    		height(root->right) == h-1 ? (1<<h) + countNodes(root->right)
    								   : (1<<h-1)  + countNodes(root->left);
    }
};*/