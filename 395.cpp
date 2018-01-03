/*
if chs[ch]<k, no substring can contain it, so we can split string by ch*/
class Solution {
public:
    int longestSubstring(string s, int k) {
    	if (s.length()==0)
    		return 0;
    	vector<int> chs(26,0);
    	for (auto ch:s)
    		chs[ch-'a'] ++;
    	for (auto ch:s)
    		if (chs[ch-'a']<k){
    			int maxL = 0;
    			string s2 = s;
    			istringstream iss(s2);
    			string ss;
    			while (getline(iss,ss,ch)){
    				maxL = max(maxL,longestSubstring(ss,k));
    				//cout<<ss<<"-"<<maxL<<endl;;
    			}
    			return maxL;
    		}
        return s.length();
    }
};