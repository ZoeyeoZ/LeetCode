//dp[i][j] = min(dp[i-1][j],s[i][j-1])+g[i][j]
//dp[i] = min(dp[i-1],dp[i])+g[i][j]

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
    	vector<int> dp(m,0);
    	dp[0] = grid[0][0];
    	for (int i=1; i<m; i++)
    		dp[i] = dp[i-1]+grid[i][0];
    	for (int j=1; j<n; j++){
    		dp[0] += grid[0][j];
    		for (int i=1; i<m; i++)
    			dp[i] = min(dp[i-1],dp[i])+grid[i][j];
    	}
    	return dp[m-1];

        
    }
};