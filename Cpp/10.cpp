// Regular Expression Matching
// eg1. aab, c*a*b -> true : s<=p
// * = 0 or more preceding element, so * cannot be the first element,
/* DP
consider eg1.
s[0..i-1] == p[0..j-1]
f[i,j] = f[i,j-1] || f[i-m,j-1] and p[j]==*
if p[j-1] != *
	f[i-1,j-1] && s[i-1]==p[j-1]
else if==*
	s:x*x while s[i-1] == x && f[i-1,j], x=1 or more
	s:x*(y) f[i,j-2], *=0
		0..i-1本来和0..j-1比较，现在比较0..j-3，即不用到（x*）
abc


	
*/
class Solution {
public:
	bool isMatch(string s, string p){
		int m = s.size(), n = p.size();
		vector<vector<bool>> f(m+1, vector<bool>(n+1, false));
		f[0][0] = true;
		for (int i=0; i<=m; i++)
			for (int j=1; j<=n; j++){
				if (p[j-1]!='*')
					f[i][j] = i>0 && f[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1] == '.');
				else 
					f[i][j] = f[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2] == '.') && f[i-1][j]);
			}
		return f[m][n];
	}
};

