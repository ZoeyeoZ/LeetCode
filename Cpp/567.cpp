//substring -> s[i..j]
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	if (s2.length()<s1.length())
    		return false;
    	vector<int> V(255,0);
    	int cnt = 0, start = 0;
    	for (char ch:s1)
    		V[ch]++;
    	for (char ch:s2){
    		if (V[ch]>0)
    			cnt++, V[ch]--;
    		else
    			while (s2[start++]!=ch)
    				V[s2[start-1]]++, cnt--;
    		if (cnt==s1.length())
    			return true;
    	}
    	return cnt == s1.length();
    }
};