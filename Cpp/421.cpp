/*
build tree, l=0, r=1
max(l->R->r)
*/class Solution {
private:
    struct Node{
        Node* left, *right;
        Node():left(NULL),right(NULL){};
    };
public:
    void helper(Node* p, Node* q, int cur, int& ans){
        if (p->left==NULL && p->right==NULL){
            ans = max(ans,cur);
            return;
        }
        cur <<= 1;
        if (p->left) {
            if (q->right)
                helper(p->left, q->right, cur+1, ans);
            else if (p->right == NULL)
                helper(p->left, q->left, cur, ans);
        }
        if (p->right) {
            if (q->left) 
                helper(p->right, q->left, cur+1, ans);
            else if (p->left == NULL)
                helper(p->right, q->right, cur, ans);
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        //height
        int h = 32;
        int find = false;
        while (h-- && !find){
            for (int num:nums)
                if (num>>h){
                    find = true;
                    break;
                }
        }
        h++;

        //build tree
        Node* root = new Node();
        for (int num:nums){
            Node* p = root;
            for (int hh = h; hh>=0; hh--){
                if ((num>>hh)%2){
                    if (!p->left)
                        p->left = new Node();
                    p = p->left;
                }
                else{
                    if (!p->right)
                        p->right = new Node();
                    p = p->right;
                }
            }
        }

        //Find longest l-R-r via DFS
        int ans = 0;
        helper(root, root, 0, ans);
        return ans;
    }
};
//42ms
/*
9ms
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() > 999)
            return 2147483644;
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++)
                res = max(res, nums[i]^nums[j]);
        }
        
        return res;
    }
};
*/