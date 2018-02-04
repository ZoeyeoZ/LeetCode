class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	if (matrix.size()==0)
    		return matrix;
    	queue<pair<int,int>> q;
    	vector<vector<int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
    	int m = matrix.size(), n = matrix[0].size();
    	int i,j;
    	for (i=0; i<m; i++)
    		for (j=0; j<n; j++)
    			if (matrix[i][j])
    				matrix[i][j] = INT_MAX;
    			else
    				q.push({i,j});
    	while (!q.empty()){
    		i = q.front().first;
    		j = q.front().second;
    		q.pop();
    		for (auto move:moves){
    			int x = i+move[0];
    			int y = j+move[1];
    			if (x>=0 && x<m && y>=0 && y<n && matrix[x][y]>=matrix[i][j]+1){
    				matrix[x][y] = matrix[i][j]+1;
    				q.push(make_pair(x,y));
    			}
    		}
    	}
    	return matrix;
        
    }
};
/*
class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    }
};
*/