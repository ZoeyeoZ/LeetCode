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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
    	vector<int> ans;
    	if (!root) return ans;
    	st.push(root); 
    	if (root->right)
    		st.push(root->right);
    	if (root->left)
    		st.push(root->left);
    	root->left = NULL;
    	root->right = NULL;
    	while (!st.empty()){
    		root = st.top();
    		//st.pop();
    		if (!(root->left || root->right)){
    			ans.push_back(root->val);
    			st.pop();
    		}
    		if (root->right)
    			st.push(root->right);
    		if (root->left)
    			st.push(root->left);
    		root->left = NULL;
    		root->right = NULL;    		
    	}
    	return ans;
    }
       
};