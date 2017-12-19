/*
1) The nth node is the new root, so newroot->left = oldroot;
2) the nth node is not root, we traverse the old tree, every time the node in the old tree has a right child, we can perform: old node->right = nth node, nth node ->left = right child; and when we reach the end of the tree, don't forget we can also add the nth node here.
*/
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
	TreeNode* helper(TreeNode* root){ //clone tree
		if (root == nullptr)
			return nullptr;
		TreeNode* newroot = new TreeNode(root->val);
		newroot->left = helper(root->left);
		newroot->right = helper(root->right);
		return newroot;
	}
    vector<TreeNode*> generateTrees(int n) {
        if (n==0)
            return {};
    	vector<TreeNode*> ans(1,nullptr);
    	for (int i=1; i<=n; i++){
    		vector<TreeNode*> tmp;
    		for (int j=0; j<ans.size();j++){
    			TreeNode* oldroot = ans[j];
    			TreeNode* root = new TreeNode(i);
    			// case 1
    			TreeNode* p = helper(oldroot);
    			root->left = p;
    			tmp.push_back(root);

    			// case 2
    			if (oldroot != nullptr){
    				TreeNode* tmpold = oldroot;
    				while (tmpold->right != nullptr){
    					TreeNode* newp = new TreeNode(i);
    					TreeNode* tmpright = tmpold->right;
    					tmpold->right = newp;
    					newp->left = tmpright;
    					TreeNode* p = helper(oldroot);
    					tmp.push_back(p);
    					tmpold->right = tmpright;
    					tmpold = tmpold->right;
    				}
    				tmpold->right = new TreeNode(i);
    				TreeNode* p = helper(oldroot);
    				tmp.push_back(p);
    				tmpold->right = nullptr;
    			}
    		}
    		ans = tmp;
    	} 
    	return ans;   
    }
};

/*

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1){
            return vector<TreeNode*> ();
        }
        return helper(1,n);
    }
    vector<TreeNode*> helper(int start, int end){
        if(start>end){
            return vector<TreeNode*> (1, nullptr);
        } else if(start == end){
            return vector<TreeNode*> (1, new TreeNode(start));
        }
        vector<TreeNode*> res;
        for(int i=start; i<=end; ++i){
            vector<TreeNode*> leftRoot = helper(start, i-1);
            vector<TreeNode*> rightRoot = helper(i+1, end);
            for(auto left: leftRoot){
                for(auto right: rightRoot){
                    TreeNode * root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
*/