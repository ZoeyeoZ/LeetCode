class Solution {
public:
    int numDecodings(string s) {
    	int len = s.length();
    	vector<int> ans(len+1,0);
    	if (len==0)
    		return 0;
    	ans[len] = 1;
    	ans[len-1] = s[len-1]=='0' ? 0:1;
    	for (int i=len-2;i>=0;i--)
    		if (s[i]!='0')
    			ans[i] = s[i+1]-48+(s[i]-48)*10<=26 ? ans[i+1]+ans[i+2]:ans[i+1];
    	return ans[0];
    }
};

/*
// method 2
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0;
        // c2: decode ways of s[i-2] , c1: decode ways of s[i-1] 
        int c1 = 1, c2 = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') c1 = 0;
             // possible two-digit letter, so new c1 is sum of both while new c2 is the old c1
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                c1 = c1 + c2;
                c2 = c1 - c2;
                // one-digit letter, no new way added
            } else {
                c2 = c1;
            }
        }
        return c1;
    }
};*/
