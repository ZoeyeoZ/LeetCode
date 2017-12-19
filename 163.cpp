class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	int l = nums.size();
    	if (l<2)
    		return 0;
    	int ans = 0;
    	vector<int> dp(nums.size(),INT_MAX);
    	dp[0] = nums[0];
    	for (int i=1;i<nums.size();i++){
    		dp[i] = min(dp[i-1],nums[i]);
    		ans = max(ans,nums[i]-dp[i]);
    	}
    	return ans;
    }
};