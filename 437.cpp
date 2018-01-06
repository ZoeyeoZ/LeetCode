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
	int helper(TreeNode* root, int pre, int sum){
		if(!root) return 0;
        int cur = pre+root->val;
        return (cur==sum) + helper(root->left, cur, sum) + helper(root->right, cur, sum);
	}
    int pathSum(TreeNode* root, int sum) {
    	if (!root)
    		return 0;
    	return helper(root,0,sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
//19
/*9
class Solution {
    unordered_map<int, int> mp;
    int ans, tar;
    void dfs(TreeNode * p, int s)
    {
        s += p->val;
        if (mp.count(s - tar))
            ans += mp[s - tar];

        mp[s]++;
        
        if (p->left)
            dfs(p->left, s);
            
        if (p->right)
            dfs(p->right, s);
        
        mp[s]--;
        s -= p->val;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        tar = sum;
        ans = 0;
        mp[0] = 1;
        dfs(root, 0);
        return ans;
    }
};*/