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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
    			ans.push_back(tmp);
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
    	for (int i=1; i<ans.size();i+=2)
    		reverse(ans[i].begin(),ans[i].end());
    	return ans;
        
    }
};