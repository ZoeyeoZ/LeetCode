class Solution {
public:
    vector<string> letterCasePermutation(string S) {
    	vector<string> res;
    	res.push_back(S);
    	int len = S.length();
    	if (len == 0)
    		return res;
    	int i = 0, l;
    	string s;
    	for (int i = 0; i < len; ++ i){
    		l = res.size();
    		if (S[i] >= '0' && S[i] <= '9')
    			continue;
    		for (int k = 0; k < l; ++ k){
    			s = res[k];
    			if (s[i] >= 'a' && s[i] <= 'z')
					s[i] = s[i] - 32;
				else if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] = s[i] + 32;
				else continue;
				res.push_back(s);
    		}
    	}
    	return res;
    }
};