/*
sol1.
https://leetcode.com/problems/target-sum/discuss/97335
		 +nums[1]
 +nums[0]-nums[1]
0		 
 -nums[0]+nums[1]
		 -nums[1]

dp[2*sum+1]
dp[k]!=0 -> nextdp[k+/-nums[i]] =+ dp[k]
dp = nextdp

sol2.
positive-negative = S
		  p-n+p+n = S+sum
			   2p = S+sum
dp[S+sum+1]
dp[s] += dp[s-nums[i]]

*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int n = nums.size();
    	if (n==0)
    		return S==0;
    	int sum = 0;
    	for (auto num:nums)
    		sum += num;
    	if (sum<S || -sum>S || (S+sum)%2!=0)
    		return 0;
    	S = (S+sum)>>1;
    	vector<int> dp(S+1,0);
    	dp[0] = 1;
    	for (auto num:nums)
    		for (int s=S;s>=num;s--)
    			dp[s] += dp[s-num];
    	return dp[S];        
    }
};