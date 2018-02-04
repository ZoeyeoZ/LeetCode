/*
dp[i][0] = i;
dp[0][j] = j;
dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
=>
row 0: dp[i] = i;
row 1..n: 
	//pre = last row[i-1], 
	tmp = row[i]
	row[i] = pre , ai=bi
			 min(pre+1,row[i]+1,row[i-1]+1), otherwise
	pre = tmp
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int pre,tmp;
        vector<int> dp(m+1,0);
        for (int j=1; j<=m; j++)
            dp[j] = j;
        for (int i=1; i<=n; i++){
            pre = dp[0];
            dp[0] = i;
            for (int j=1; j<=m; j++){
                tmp = dp[j];
                dp[j] = min(pre+(word1[j-1]!=word2[i-1]),min(dp[j-1]+1,dp[j]+1));
                pre = tmp;
            }
        }
        return dp[m];
    }
};