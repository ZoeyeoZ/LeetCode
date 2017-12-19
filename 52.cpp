class Solution {
public:
	int allans;
    int totalNQueens(int n) {
    	vector<int> ans;
    	helper(n, ans, 0, 0, 0);
    	return allans;
    }
    void helper(int n, vector<int> queens, int col, int x1, int x2){
    	if (queens.size()==n){
    		allans ++;
    		return;
    	}
    	int allpos = (1<<n) -1, pos, p;
    	pos = allpos & ~(col|x1|x2);
    	while (pos){
    		p = pos & (~pos+1);
    		pos -= p;
    		vector<int> tmp = queens;
    		int k = 0, tmpp = p;
    		while (tmpp >>= 1)
    			k++;
    		tmp.push_back(k);
    		helper(n, tmp, col|p, (x1|p)<<1, (x2|p)>>1);
    	}

    }
};