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
    TreeNode* deleteNode(TreeNode* root, int key) {
    	if (!root) return root;
    	if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else{
    		if (root->right){
    			TreeNode* p = root->right;
    			while (p->left)
    				p = p->left;
    			root->val = p->val;
    			root->right = deleteNode(root->right, p->val);
    		}
    		else{
    			TreeNode* p = root->left;
    			delete root;
    			return p;
    		}
    	}
    	return root;
        
    }
};