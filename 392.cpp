class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int l1 = s.length(), l2 = t.length();
    	int i = 0, j = 0;
    	while (i<l1 && j<l2)
    		if (s[i]==t[j])
    			i++,j++;
    		else j++;
    	return i==l1 ? true:false;
    }
};