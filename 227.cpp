class Solution {
public:
    int calculate(string s) {
        int ans = 0, tmp = 0, l = s.length();
        char op = '+';
        int i=0;
        while (i<l){
        	while (s[i]==' ' && i<l)
        		i++;
        	if (s[i]>='0' && s[i]<='9'){
        		int num = s[i] -'0';
        		while (++i<l && s[i]>='0' && s[i]<='9')
        			num = num*10+s[i]-'0';
        		switch(op){
        			case '+': tmp += num; break;
        			case '-': tmp -= num; break;
        			case '*': tmp *= num; break;
        			case '/': tmp /= num; break;
        		}
        	}else {
        		if (s[i]=='+' || s[i]=='-'){
        			ans += tmp;
        			tmp = 0;
        		}
        		op = s[i++];
        	}
        }
        return ans+tmp;
    }
};