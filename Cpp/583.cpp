class Solution {
public:
    int minDistance(string word1, string word2) {
    	int l1 = word1.length(), l2 = word2.length();
    	vector<vector<int>> dp;
    	for (int i=0;i<=l1;i++){
    		vector<int> row(l2+1,0);
    		dp.push_back(row);
    	}
    	for (int i=1; i<=l1; i++)
    		for (int j=1; j<=l2; j++){
    			if (word1[i-1]==word2[j-1])
    				dp[i][j] = dp[i-1][j-1]+1;
    			dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
    		}
        return l1+l2-2*dp[l1][l2];
    }
};