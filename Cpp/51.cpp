class Solution {
public:
	vector<vector<string>> allans;
    vector<vector<string>> solveNQueens(int n) {
    	vector<int> ans;
    	helper(n, ans, 0, 0, 0);
    	return allans;
    }
    void helper(int n, vector<int> queens, int col, int x1, int x2){
    	if (queens.size()==n){
    		vector<string> ans;
    		string s;
    		for (int i:queens){
    			s = "";
    			for (int j=0;j<i;j++)
    				s += '.';
    			s += 'Q';
    			for (int j=i+1;j<n;j++)
    				s += '.';
    			ans.push_back(s);
    		}
    		allans.push_back(ans);
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