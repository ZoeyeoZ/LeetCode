/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (!root)
    		return;
    	TreeLinkNode* nxtH = NULL;
    	TreeLinkNode* nxtP = NULL;
    	while (root){
    		while (root){
    			if (root->left){
    				if (nxtP)
    					nxtP->next = root->left;
    				else
    					nxtH = root->left;
    				nxtP = root->left;
    			}
    			if (root->right){
    				if (nxtP)
    					nxtP->next = root->right;
    				else
    					nxtH = root->right;
    				nxtP = root->right;
    			}
    			root = root->next;
    		}
    		root = nxtH;
    		nxtH = NULL;
    		nxtP = NULL;
    	}
    }
};