class Solution {
public:
	int m, n, ans = 1;
	vector<vector<int>> dp;
    vector<vector<int>> matrix;
	vector<vector<int>> moves={{-1,0},{0,-1},{1,0},{0,1}};
	int dfs(int x, int y){
		if (dp[x][y]) return dp[x][y];
		for (auto move : moves){
			int xx = x+move[0], yy = y+move[1];
			if (xx<0 || xx>=m || yy<0 || yy>=n || matrix[xx][yy]<=matrix[x][y])
				continue;
			dp[x][y] = max(dp[x][y],dfs(xx,yy));
		}
		return ++dp[x][y];

	}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    	m = matrix.size();
    	if (m==0)
    		return 0;
    	n = matrix[0].size();
    	dp = vector<vector<int>>(m,vector<int>(n,0));
    	for (int i=0;i<m;i++)
    		for (int j=0;j<n;j++)
    			ans = max(ans,dfs(i,j));
        return ans;
    }
};