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
    vector<int> largestValues(TreeNode* root) {
    	vector<int> ans;
        if (root==NULL)
            return ans;
    	queue<pair<TreeNode*,int>> q;
    	q.push(make_pair(root,0));
    	int l;
    	while (!q.empty()){
    		root = q.front().first;
    		l = q.front().second;
    		q.pop();
    		if (ans.size()<l+1)
    			ans.push_back(root->val);
    		else
    			ans[l] = max(ans[l],root->val);
    		if (root->left)
    			q.push(make_pair(root->left,l+1));
    		if (root->right)
    			q.push(make_pair(root->right,l+1));
    	}
        return ans;
    }
};
/*9ms
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        list<TreeNode*> current;
        
        if (root != nullptr) {
            current.push_back(root);
        }
        
        while (current.size()) {
            int max_value = INT_MIN;
            int size = current.size();
            while (size) {
                TreeNode* node = current.front();
                max_value = max(max_value, node->val);
                current.pop_front();
                if (node->left != nullptr) {
                    current.push_back(node->left);
                }
                
                if (node->right != nullptr) {
                    current.push_back(node->right);
                }
                size--;
            }
            result.push_back(max_value);
        }
        
        return result;
    }
};
*/