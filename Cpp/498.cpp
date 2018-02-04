class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    	vector<int> ans;
        int m, n;
    	if ((m = matrix.size())==0 || (n = matrix[0].size())==0)
    		return ans;
    	for (int i=0; i<m+n-1;i++)
    		if (i%2)
    			for (int j = min(n-1,i); j >= max(i-m+1,0); j--)
    				ans.push_back(matrix[i-j][j]);
    		else for (int j = max(i-m+1,0); j <= min(n-1,i); j++)
    				ans.push_back(matrix[i-j][j]);
    	return ans;
    }
};