class Solution {
public:
	string helper(string s, int &i){
		string ans="";
    	int l = s.length();
    	while (i<l && s[i]!=']'){
    		if (!isdigit(s[i]))
    			ans += s[i++];
    		else {
    			int n = 0;
    			while (i<l && isdigit(s[i]))
    				n = n*10+s[i++]-'0';
    			i++;//[
    			string tmp = helper(s,i);
    			i++;//]
    			while (n--)
    				ans += tmp;
    		}

    	}
    	return ans;
	}
    string decodeString(string s) {
    	int i=0;
    	return helper(s,i);
    	
    }
};