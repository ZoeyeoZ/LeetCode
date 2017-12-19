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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	stack<vector<int>> anstmp;
    	vector<vector<int>> ans;
    	if (!root)
    		return ans;
    	queue<TreeNode*> q;
    	q.push(root);
    	q.push(NULL);
    	vector<int> tmp;
    	while (!q.empty()){
    		TreeNode* t = q.front();
    		q.pop();
    		if (t==NULL){
    			anstmp.push(tmp);
    			tmp.resize(0);
    			if (!q.empty())
    				q.push(NULL);
    		}
    		else{
    			tmp.push_back(t->val);
    			if (t->left)
    				q.push(t->left);
    			if (t->right)
    				q.push(t->right);
    		}

    	}
    	while (!anstmp.empty()){
    		ans.push_back(anstmp.top());
    		anstmp.pop();
    	}
    	return ans;
       
    }
};