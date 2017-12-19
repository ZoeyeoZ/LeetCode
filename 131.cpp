class Solution {
public:
    vector<vector<string>> partition(string s) {
    	int l = s.length();
    	vector<vector<string>> anstmp;
    	vector<vector<vector<string>>> ans(l+1,anstmp);
    	ans[0] = {{}};
    	vector<vector<bool>> dp(l,vector<bool>(l,false));
    	for (int i=0;i<l;i++)
    		for (int j=0;j<=i;j++)
    			if (s[i]==s[j] && (i-j<=1 || dp[j+1][i-1])){
    				dp[j][i] = true;
    				string tmp = s.substr(j,i-j+1);
    				for (vector<string> k:ans[j]){
    					k.push_back(tmp);
    					ans[i+1].push_back(k);
    				}
    			}
    	return ans[l];
    }
};