class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (auto dd:d){
        	int i = 0, j = 0;
        	for (;i<s.size() && j<dd.size();i++)
        		if (s[i]==dd[j])
        			j++;
        	if (j==dd.length() && (ans.length()<dd.length() || (ans.length()==dd.length() && ans>dd)))
        		ans = dd;
        }
        return ans;
    }
};