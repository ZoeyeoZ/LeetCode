class Solution {
public:
    int numSquares(int n) {
    	const int l = sqrt(n);
    	if (n==l*l)
    		return 1;
    	vector<int> dp(n+1,INT_MAX);
    	dp[0]=0;
    	for (int i=1;i<=l;i++){
    		int i2=i*i;
    		for(int j=i2;j<=n;j++)
    			if (dp[j] > dp[j-i2]+1)
    				dp[j] = dp[j-i2]+1; 
    	}
    	return dp[n];
        
    }
};