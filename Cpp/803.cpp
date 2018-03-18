// Each time, check the erasure,  some other bricks may drop because of that erasure
// An erasure may refer to a location with no brick - if it does, no bricks drop
/*class Solution {
public:
	int n, m;
	vector<vector<int>> moves={{0,-1},{0,1},{-1,0},{1,0}};
	bool valid(int x, int y){
		if (x<0 || x>=n || y<0 || y>=m)
			return false;
		return true;
	}
	bool linked(int x, int y, vector<vector<int>>& grid){
		for (auto move:moves){
			int xx = x + move[0], yy = y + move[1];
        	if (!valid(xx,yy) || grid[xx][yy] !=0)
        		return true;
        }
        return false;
	}
	int helper(vector<vector<int>>& grid, int x, int y){
		int ans = 1;
		if (!valid(x,y) || grid[x][y] == 0)
			return 0;
		else{
			grid[x][y] = 0;
			for (auto move:moves){
					int xx = x + move[0], yy = y + move[1];
					cout << "move:"<<xx<<","<<yy<<endl;
        			if (!valid(xx,yy) || grid[xx][yy] == 0 || xx == 0)
        				continue;
        			ans += helper(grid, xx, yy);
        			cout << xx<<","<<yy<<endl;
			}
		}
		return ans;
	}
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int t = hits.size();
        vector<int> ans(t,0);
        n = grid.size();
        if (n == 0)
        	return ans;
        m = grid[0].size();
        for (int i = 0; i < t; ++i){
        	int x = hits[i][0], y= hits[i][1];
        	if (grid[x][y] > 0){
        		cout<< x<<","<<y<<":"<<endl;
        		ans[i] += helper(grid, x, y);
        	}
        }
        for(auto i:ans)
        	cout<<i-1<<",";
        return ans;
    }
};
*/

class Solution {
public:
	int n, m;
	vector<vector<int>> moves={{0,-1},{0,1},{-1,0},{1,0}};
	bool valid(int x, int y){
		if (x<0 || x>=n || y<0 || y>=m)
			return false;
		return true;
	}
	int dfs(vector<vector<int>>& grid, int x,int y){
		if (!valid(x,y) || (grid[x][y] == 0 || grid[x][y] == 3) )//(grid[x][y]+1)/2!=1)
			return 0;
		grid[x][y] = 3;
		int ans = 1;
		for (auto move:moves)
			ans += dfs(grid, x+move[0], y+move[1]);
        return ans;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		int t = hits.size();
        vector<int> ans(t,0);
        n = grid.size();
        if (n == 0)
        	return ans;
        m = grid[0].size();
        vector<bool> hb;
        for (auto hit:hits){
        	hb.push_back(grid[hit[0]][hit[1]] == 1); 
        	grid[hit[0]][hit[1]] = 0;
        }
        for (int i = 1; i < n; ++ i)
            for (int j = 0;j < m; ++ j)
                if (grid[i][j] == 1)
                	grid[i][j] = 2;//linked from others;
        for (int j = 0;j < m; ++ j)
	        if (grid[0][j] == 1)
	        	dfs(grid,0,j); // linked from top;
	    for (int k = t-1; k >= 0; --k)
	    	if (hb[k]){
	    		int x = hits[k][0], y= hits[k][1];
	    		grid[x][y] = 2;
	    		bool exist = (x==0); // on the top, won't fall
	    		for (auto move:moves){
	    			int xx = x + move[0],yy = y +move[1];
	    			exist |= (valid(xx,yy) && grid[xx][yy] == 3); // linked by the top, won't fall;
	    		}
	    		if (!exist)
	    			continue;
	    		ans[k] = dfs(grid,x,y)-1;
	    }
	    return ans;
	}
};
    