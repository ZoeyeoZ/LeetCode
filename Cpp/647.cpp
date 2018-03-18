/*
palindromic strings:
base:
	[i][i]=1, cnt-n
	i = 0..n-1
	j = 0..i-1
		(dp[j+1][i-1]||i==j+1) && s[i]==s[j]

	return cnt
*/
class Solution {
public:
    int countSubstrings(string s) {
    	int n = s.length();
    	int cnt = n;
    	vector<vector<int>> dp(n,vector<int>(n,0));
    	for (int i = 0; i < n; i++){
    		dp[i][i] = 1;
    		for (int j = 0; j < i; j++)
    			if ((dp[j+1][i-1]||i==j+1) && s[i]==s[j]){
    				dp[j][i] = 1;
    				cnt++;
    			}
    	}
    	return cnt;       
    }
};
/*
O(1)
int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
        }
        return res;
    }

int countSubstrings(string s) {
    int num = s.size();
    for(float center = 0.5; center < s.size(); center += 0.5) {
        int left = int(center - 0.5), right = int(center + 1);
        while(left >= 0 && right < s.size() && s[left--] == s[right++]) ++num;
    }
    return num;
} 

*/