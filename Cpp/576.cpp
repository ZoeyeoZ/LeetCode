/*
% 1000000007;
k=1..N,i=0..m-1,j=0..n-1
dp[k][i][j] = i==0 ? 1 : dp[k-1][i-1][j]
			+ i==m-1 ? 1 : dp[k-1][i+1][j]
			+ j==0 ? 1 : dp[k-1][i][j-1]
			+ j==n-1 ? 1 : dp[k-1][i][j+1]
to reduce space -> k=0/1
*/
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
    	unsigned int dp[2][50][50] = {};
    	int k1,k2;
    	for (int k = 0; k < N; k ++){
    		for (int i = 0; i < m; i ++)
    			for (int j = 0; j < n; j++){
    				k1 = k % 2;
    				k2 = 1 - k1;
    				dp[k1][i][j] = ((((i==0 ? 1 : dp[k2][i-1][j])
								 + (i==m-1 ? 1 : dp[k2][i+1][j])) % 1000000007
								 + (j==0 ? 1 : dp[k2][i][j-1])) % 1000000007
								 + (j==n-1 ? 1 : dp[k2][i][j+1])) % 1000000007;
    			}
    	}
    	return dp[1-N%2][i][j];
    }
};