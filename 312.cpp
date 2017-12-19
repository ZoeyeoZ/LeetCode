class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	int n = nums.size();
    	nums.insert(nums.begin(),1);
    	nums.insert(nums.end(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for (int l=1;l<=n; l++)
        	for (int i=1;i<=n-l+1;i++){
        		int j = i+l-1;
        		int ans = 0, tmp;
        		for (int k=i;k<=j;k++){
        			tmp = dp[i][k-1]+dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1];
        			if (tmp>ans)
        				ans = tmp;
        		}
        		dp[i][j] = ans;
        	}
        return dp[1][n];
    }
};