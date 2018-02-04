/*
dp-minmax
k+max(dp[i][k-1],dp[k+1][k])
dp[i][j] = min(..)
*/
class Solution {
public:
    int getMoneyAmount(int n) {
    	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    	for (int j=2;j<=n;j++)
    		for (int i=j-1;i>0;i--){
    			int mindp = INT_MAX;
    			for (int k=i+1;k<j;k++)
    				mindp = min(mindp, k+max(dp[i][k-1],dp[k+1][j]));
    			dp[i][j] = (i+1==j ? i:mindp);
    		}
    	return dp[1][n];   
    }
};
