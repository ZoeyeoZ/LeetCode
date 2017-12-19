
//230. Kth Smallest Element in a BST
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	stack<TreeNode*> s;
    	TreeNode* cur = root;
    	while (cur || !s.empty()){
    		while (cur){
    			s.push(cur);
    			cur = cur->left;
    		}
    		cur = s.top();
    		s.pop();
    		if (--k == 0)
    			return cur->val;
    		cur = cur->right;


    	}
    	return -1;        
    }
};
