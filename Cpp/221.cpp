//221. Maximal Square
/*
if aij==1,
	dp[i][j]=min(dp[i-1][j-1],d[[i-1][j],d[i][j-1])+1
else 0
=>
k = dp[j-1] (last row)
dp[j] = min(k,dp[j-1],dp[j])+1
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if ((matrix.size()==0)||(matrix[0].size()==0))
    		return 0;
    	int k1, k2, ans=0;
    	vector<int> dp(matrix[0].size(),0);
        for (int i=0;i<matrix.size();i++){
        	if (i>0)
        		k1 = dp[0];
        	else 
        		k1 = 0;
        	if (matrix[i][0]=='1')
        		dp[0] = 1;
        	else dp[0] = 0;
        	if (dp[0]>ans) ans=dp[0];
        	for (int j=1;j<matrix[0].size();j++){
        		k2 = dp[j];
        		if (matrix[i][j]=='1')
        			dp[j]=min(k1,min(dp[j-1],dp[j]))+1;
        		else
        			dp[j]=0;
        		if (dp[j]>ans) ans=dp[j];
        		k1 = k2;
        	}
        }
    	return ans*ans;
    }
};