class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	int l = s.length();
    	vector<vector<int>> dp(l,vector<int>(l,0));
    	for (int i=0; i<l; i++)
    		dp[i][i] = 1;
    	for (int len=2; len<=l; len++)
    		for (int i=0; i<=l-len; i++){
    			int j = i+len-1;
    			dp[i][j] = (s[i]==s[j] ? dp[i+1][j-1]+2 : max(dp[i+1][j],dp[i][j-1])); 
    		}
        return dp[0][l-1];
    }
};

/* int longestPalindromeSubseq(string s) {
        if (s.size() == 0) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >=0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][s.size() - 1];
    }*/
/*22
class Solution {
public:
   
    int longestPalindromeSubseq(string s) {
        if (s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
        for (int i = s.size() - 1; i >=0; i--) {
            int prev = 1;
            for (int j = i + 1; j < s.size(); j++) {
                int curr;
                if (s[i] == s[j]) curr = 2 + dp[j - 1];
                else curr = max(prev, dp[j]);
                dp[j - 1] = prev;
                prev = curr;
            }
            dp[s.size() - 1] = prev;
        }
        return dp[s.size() -1];
    }
};
*/