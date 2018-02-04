class Solution {
public:
    bool isNumber(string s) {
        int i =0;
        for (; s[i] == ' ';i++){}
        if (s[i] == '+' || s[i] == '-')
        	i++;
        int nm,pt;
        for (nm=0, pt=0;(s[i]<='9' && s[i]>='0')||s[i]=='.';i++)
        	s[i] == '.'? pt++:nm++;
        if (pt>1 || nm<1)
        	return false;

        if (s[i]=='e'){
        	i++;
        	if (s[i] == '+' || s[i] == '-')
        		i++;
	        	for (nm=0;s[i]<='9' && s[i]>='0';i++,nm++){}
	        	if (nm<1)
        			return false;
        }

        for (; s[i] == ' ';i++){}
        return s[i]==0;
    }
};