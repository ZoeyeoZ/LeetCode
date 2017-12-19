class Solution {
public:
    int calculate(string s) {
    	int l = s.length(), ans = 0;
    	vector<int> signs(2,1);
    	for (int i=0; i<l; i++){
    		if (s[i]>='0'){
    			int num = 0;
    			while (i<l && s[i]>='0')
    				num = num*10 + s[i++]-'0';
    			ans += signs.back()*num;
    			signs.pop_back();
    			i--;
    		}
    		else if (s[i]==')')
            	signs.pop_back();
        	else if (s[i] != ' ')// + or ( -> add 1, - -> add -1)
            	signs.push_back(signs.back() * (s[i] == '-' ? -1 : 1));
    	}
   	 	return ans;
   	 }
};

/*
9ms
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, sign = 1;
        for(int i = 0; i < s.length(); ) {
            
            if('0' <= s[i] && '9' >= s[i]) {
                int num = 0;
                while(i < s.length() && ('0' <= s[i]) && ('9' >= s[i])) {
                    num = (10 * num) + s[i] - '0';
                    i ++;
                }
                res += (sign * num);
            } else if (' ' == s[i]) {
                while(i < s.length() && ' ' == s[i]) {
                    i ++;
                }
            } else if ('(' == s[i]) {
                st.push(res); st.push(sign);
                res = 0; sign = 1;
                i ++;
            } else if (')' == s[i]) {
                res = res * st.top(); st.pop();
                res += st.top(); st.pop();
                i ++;
            } else {
                sign = ('+' == s[i]) ? 1 : -1;
                i ++;
            }
        }
        return res;
    }
};
*/