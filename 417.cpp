//BFS
class Solution {
public:
	void helper(vector<vector<int>> matrix, vector<vector<bool>>& visited, queue<pair<int,int>>& q){
		int n = matrix.size();
    	int m = matrix[0].size();
		vector<vector<int>> moves={{-1,0},{0,-1},{1,0},{0,1}};
		while (!q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (auto move:moves){
				int xx = x+move[0], yy = y+move[1];
				if (xx<0 || xx>=n || yy<0 || yy>=m || visited[xx][yy] || matrix[xx][yy] < matrix[x][y])
					continue;
				visited[xx][yy] = true;
				q.push(make_pair(xx,yy));
			}
		}
	}
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    	vector<pair<int, int>> ans;
    	int n = matrix.size();
    	if (n==0)
    		return ans;
    	int m = matrix[0].size();
    	if (m==0)
    		return ans;
    	vector<vector<bool>> visited1(n,vector<bool>(m,false));
    	vector<vector<bool>> visited2(n,vector<bool>(m,false));
    	queue<pair<int,int>> q1, q2;
    	for (int i=0;i<m;i++){
    		visited1[0][i] = true;
    		q1.push(make_pair(0,i));
    		visited2[n-1][i] = true;
    		q2.push(make_pair(n-1,i));
    	}
    	for (int i=1;i<n;i++){
    		visited1[i][0] = true;
    		q1.push(make_pair(i,0));
    	}
    	for (int i=0;i<n-1;i++){
    		visited2[i][m-1] = true;
    		q2.push(make_pair(i,m-1));
    	}
    	helper(matrix, visited1, q1);
    	helper(matrix, visited2, q2);

    	for (int i=0;i<n;i++)
    		for (int j=0;j<m;j++)
    			if (visited1[i][j] && visited2[i][j])
    				ans.push_back(make_pair(i,j));
        return ans;
    }
};