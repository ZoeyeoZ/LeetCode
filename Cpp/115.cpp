class Solution {
public:
    int numDistinct(string s, string t) {
    	int l1 = s.length(), l2 = t.length(), tmp, pre;
    	vector<int> dp(l2+1,0);
    	dp[0] = 1;
    	for (int i=1;i<=l1;i++){
    		pre = 1;
    		for (int j=1;j<=l2;j++){
    			tmp = dp[j];
    			dp[j] = dp[j] + (s[i-1]==t[j-1] ? pre:0);
    			pre = tmp;
    		}
    		cout << endl;
    	}
    	return dp[l2];
    }
};