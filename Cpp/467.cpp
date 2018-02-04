/*
s="abcd...za...z..."
abs(p[i]-p[i-1])==1, dp[i] = dp[i-1]+maxL, if not in set
=>
dp(26,0)
caculate the maxL
		dp[p[0]-'a'] = 1;
        for (int i=1; i<l; i++){
        	if (p[i]-p[i-1]==1 || p[i-1]=='z' && p[i]=='a')
        		dp[p[i]-'a'] = max(dp[p[i]-'a'],dp[p[i-1]-'a']+1);
        		//Wrong, maybe the storing is the former maxlength, not here
        	else
        		dp[p[i]-'a'] = max(dp[p[i]-'a'],1);
        }
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
    	int l = p.length();
    	if (l<=1)
    		return l;
        vector<int> dp(26,0);
        int len = 1;
        dp[p[0]-'a'] = 1;
        for (int i=1; i<l; i++){
        	if (!(p[i]-p[i-1]==1 || p[i-1]=='z' && p[i]=='a'))
        		len = 0;
        	dp[p[i]-'a'] = max(dp[p[i]-'a'],++len);

        }
        int ans = 0;
        for (auto i:dp)
        	ans += i;
        return ans;
    }
};