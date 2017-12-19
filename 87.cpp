class Solution {
public:
    bool isScramble(string s1, string s2) {
    	int m = s1.length(), n = s2.length();
    	if (m!=n)
    		return false;
    	if (s1==s2)
    		return true;
    	vector<vector<vector<bool>>> dp(m,vector<vector<bool>>(m,vector<bool>(m+1,false)));
    	for (int l=1; l<=m; l++)
    		for (int i=0; i+l<=m; i++)
    			for (int j=0; j+l<=m; j++)
    				if (l==1)
    					dp[i][j][l] = s1[i]==s2[j];
    				else 
    					for (int k=1; k<l && !dp[i][j][l]; k++)
    						dp[i][j][l] = (dp[i][j][k]&&dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k]&&dp[i+k][j][l-k]);
    	return dp[0][0][m]; 
    }
};