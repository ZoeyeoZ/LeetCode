/*
sol1.
caculate the adj
i -> 4-i

sol2.
remove 2, if they're adj
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    	int cnt = 0, rpt = 0;
    	if (grid.size()==0 || grid[0].size()==0)
    		return 0;
    	int n = grid.size(), m = grid[0].size();
    	for (int i=0; i<n; i++)
    		for (int j=0; j<m; j++)
    			if (grid[i][j]==1){
    				cnt++;
    				if (i!=0 && grid[i-1][j] == 1) rpt++;
    				if (j!=0 && grid[i][j-1] == 1) rpt++;
    			}
    	return 4*cnt-2*rpt;
    }
};