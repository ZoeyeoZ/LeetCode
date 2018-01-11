/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Longest substring in In-Order
class Solution {
public:
	void inorder(TreeNode* root, vector<int>& ans,int&maxc, int& cur, int& curv){
		if (root==NULL)
			return;
		inorder(root->left,ans,maxc,cur,curv);
		if (root->val != curv){
			curv = root->val;
			cur = 0;
		}
		cur++;
		if (cur>maxc){
			maxc = cur;
			ans = {curv};
		}
		else if (cur==maxc)
			ans.push_back(curv);
		inorder(root->right,ans,maxc,cur,curv);
		return;
	}
    vector<int> findMode(TreeNode* root) {
    	int cur = 0, curv = -1, maxc = 0;
    	vector<int> ans;
    	inorder(root, ans, maxc, cur, curv);
    	return ans;
    }
};