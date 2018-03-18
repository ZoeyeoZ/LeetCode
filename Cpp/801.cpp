class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	int l = A.size();
    	if (l == 0)
    		return 0;
    	vector<vector<int>> dp(l,vector<int>(2,l));
    	dp[0][0] = 0;
    	dp[0][1] = 1;
    	for (int i = 1; i < l; ++ i){
    		if (A[i-1]<A[i] && B[i-1]<B[i]){
    			dp[i][0] = min(dp[i][0],dp[i-1][0]);
    			dp[i][1] = min(dp[i][1],dp[i-1][1]+1);
    		}
    		if (A[i-1]<B[i] && B[i-1]<A[i]){
    			dp[i][0] = min(dp[i][0],dp[i-1][1]);
    			dp[i][1] = min(dp[i][1],dp[i-1][0]+1);
    		}

    	}
    	return min(dp[l-1][0],dp[l-1][1]);
    }
};