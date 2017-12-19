class Solution {
public:
	vector<vector<int>> moves={{0,-1},{0,1},{-1,0},{1,0}};
	int m,n;
    int numIslands(vector<vector<char>>& grid) {
    	int ans = 0;
    	m = grid.size();
    	if (m==0)
    		return ans;
    	n = grid[0].size();
    	for (int i=0; i<m;i++)
    		for (int j=0; j<n;j++)
    			if (grid[i][j]=='1'){
    				helper(grid,i,j);
    				ans++;
    			}
    	return ans;
        
    }
    bool valid(int x, int y){
    	return (x>=0)&&(x<m)&&(y>=0)&&(y<n);
    }
    void helper(vector<vector<char>>& grid,int x, int y){
    	int xx,yy;
    	grid[x][y] = '0';
    	for (int k=0;k<4;k++){
    		xx = x+moves[k][0];
    		yy = y+moves[k][1];
    		if (valid(xx,yy) && grid[xx][yy]=='1')
    			helper(grid,xx,yy);
    	}
    }
};