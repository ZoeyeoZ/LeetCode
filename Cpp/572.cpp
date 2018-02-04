/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
t: caculate the depth from the node
s: find the candidate subtree root
comapre
*/
class Solution {
public:
	vector<TreeNode*> cands;
	int getDepth(TreeNode* root, int d){
		if (!root)
			return -1;
		int depth = max(getDepth(root->left,d),getDepth(root->right,d))+1;
		if (depth == d)//find candidates
			cands.push_back(root);
		return depth;
	}
	bool isSub(TreeNode* n, TreeNode* t){
		if (!n && !t)
    		return true;
    	if (!n || !t || n->val!=t->val)
    		return false;
    	return isSub(n->left,t->left) && isSub(n->right,t->right);
	}
    bool isSubtree(TreeNode* s, TreeNode* t) {
    	if (!s && !t)
    		return true;
    	if (!s || !t)
    		return false;
    	getDepth(s,getDepth(t,-1));
    	for (auto n:cands)
    		if (isSub(n, t))
    			return true;
   		return false;
    }
};
/*19
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t==NULL){
            return true;
        }
        
        if(s==NULL){
            return false;
        }
        
        if(s->val==t->val){
            if(matchTree(s->left,t->left)&&matchTree(s->right,t->right)){
                return true;
            }
        }
        
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    
private:
    bool matchTree(TreeNode* t1, TreeNode* t2){
        if(t1==NULL&&t2==NULL){
            return true;
        }
        
        if(t1==NULL||t2==NULL){
            return false;
        }
        
        return (t1->val==t2->val)&&matchTree(t1->left,t2->left)&&matchTree(t1->right,t2->right);
    }
};*/