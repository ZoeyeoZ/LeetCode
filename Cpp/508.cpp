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
	int helper(TreeNode* root,unordered_map<int,int>& VM, int& maxcnt){
		if (root==NULL)
			return 0;
		int sum = root->val;
		sum += helper(root->left, VM, maxcnt) + helper(root->right, VM, maxcnt);
		VM[sum]++;
		maxcnt = max(maxcnt,VM[sum]);
		return sum;
	}
    vector<int> findFrequentTreeSum(TreeNode* root) {
    	unordered_map<int,int> VM;
    	int maxcnt = 0;
    	helper(root, VM, maxcnt);
    	vector<int> ans;
    	for (auto v:VM)
    		if (v.second == maxcnt)
    			ans.push_back(v.first);
    	return ans;
    }
};