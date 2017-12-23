/*
0-0
1-1
2-1,2
4-1,2,2,3
8-1,2,2,3,
dp[0] = 0;
dp[1] = dp[1-1] + 1;
dp[2] = dp[2-2] + 1;
dp[3] = dp[3-2] +1;
dp[4] = dp[4-4] + 1;
dp[5] = dp[5-4] + 1;
dp[6] = dp[6-4] + 1;
dp[7] = dp[7-4] + 1;
dp[8] = dp[8-8] + 1;
dp[index] = dp[index - offset] + 1;
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i=1; i<=num; ++i)
        	if(i%2 == 0) 
        		dp[i] = dp[i/2];
            else 
            	dp[i] = dp[i-1] + 1;
        return dp;
    }
};
//ret[i] = ret[i&(i-1)] + 1;