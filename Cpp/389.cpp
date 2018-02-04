class Solution {
public:
    char findTheDifference(string s, string t) {
    	/*Wrong..the position can be changed..
    	int l = s.length(), i = 0;
    	while (i<l && s[i]==t[i])
    		i++;
    	return t[i];
    	*/
    	char ans = 0;
    	for (char ch:s)
    		ans ^= ch;
    	for (char ch:t)
    		ans ^= ch;
    	return ans;
    }
};