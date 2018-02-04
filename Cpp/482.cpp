/*
sol1.
Remove all -, then add

sol2.
Since the first can be less than k, we process from the end
And ever k+1 position should be '-'
*/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
    	string ans = "";
    	for (int i=S.length()-1;i>=0;i--)//for (auto i = S.rbegin(); i < S.rend(); i++), *i
    		if (S[i]!='-')
    			(ans.size()%(K+1)-K ? ans:ans+="-") += toupper(S[i]);
    	reverse(ans.begin(),ans.end());
    	return ans;
    }
};