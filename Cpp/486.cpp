/*
DP:
	len=0, =nums[i]
	len=1..n-1,i=0..n-1
		int j = i + len;
	    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
=>O(n) space
	i=n-1..0;
	j=i..n-1;
	dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	int n = nums.size();
    	if ((n&1)==0) // even
    		return true;
    	vector<int> dp(n,0);
    	for (int i=n-1;i>=0;i--)
    		for (int j=i;j<n;j++)
    			if (i==j)
    				dp[j] = nums[j];
    			else 
    				dp[j] = max(nums[i]-dp[j],nums[j]-dp[j-1]);
    	return dp[n-1]>=0;
    }
};