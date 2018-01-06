/*
sol1.
KMP
https://leetcode.com/problems/repeated-substring-pattern/discuss/94397
sol2.
substr.l = 1..l/2
=>new str:right+left
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    	int l = s.length();
    	if (l==0)
    		return false;
    	for (int i=1; i<=l/2; i++)
    		if (l%i==0)
    			if (s==s.substr(i)+s.substr(0,i))
    				return true;
        return false;
    }
};