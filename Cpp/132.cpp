class Solution {
public:
    int minCut(string s) {
    	int l = s.length();
    	vector<vector<bool>> dp(l,vector<bool>(l,false));
    	vector<int> ans(l+1);
    	for (int i=0; i<=l; i++)
    		ans[i] = i-1;
    	for (int i=0;i<l;i++)
    		for (int j=0;j<=i;j++)
    			if (s[i]==s[j] && (i-j<=1 || dp[j+1][i-1])){
    				dp[j][i] = true;
    				ans[i+1] = min(ans[i+1],1+ans[j]);
    			}
    	return ans[l];
    }
};