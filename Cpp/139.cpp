class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	int l = s.length(), n = wordDict.size();
    	if (n==0)
    		return false;
    	vector<bool> dp(l+1,false);
    	unordered_map<string,int> Wmap;
    	dp[0] = true;
    	for (int j=0;j<n;j++)
    		Wmap[wordDict[j]] = 1;
    	for (int i=1;i<=l;i++)
    		for (int j=0;j<i;j++)
    			if (dp[j] && Wmap[s.substr(j,i-j)])
    				dp[i] = true;
    
        return dp[l];
    }
};