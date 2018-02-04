//Union-Find
class Solution {
public:
	int find(int i, vector<int>& pa){
		while (pa[i]!=i){
			pa[i] = pa[pa[i]];
			i = pa[i];
		}
		return i;
	}
    int findCircleNum(vector<vector<int>>& M) {
    	if (M.size()==0)
    		return 0;
    	int m = M.size();
    	vector<int> pa(m,0);
    	for (int i=0;i<m;i++)
    		pa[i] = i;

    	int ans = m;
    	for (int i=0; i<m; i++)
    		for (int j=0; j<m; j++)
    			if (M[i][j]){
    				int p1 = find(i,pa);
    				int p2 = find(j,pa);
    				if (p1!=p2){
    					pa[p1] = p2;
    					ans--;
    				}
    			}
        return ans;
    }
};