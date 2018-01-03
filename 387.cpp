class Solution {
public:
    int firstUniqChar(string s) {
    	vector<int> le(26,0);
    	for (int i=0;i<s.length();i++)
    		le[s[i]-'a']++;
    	for (int i=0;i<s.length();i++)
    		if (le[s[i]-'a']==1)
    			return i;
    	return -1;
    }
};