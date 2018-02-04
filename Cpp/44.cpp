class Solution {
public:
    bool isMatch(string s, string p) {
    	int i=0, j=0, tmp=-1, tmps = 0;
    	while (i<s.length()){
    		cout<<p[j]<<",";
    		if ((s[i]==p[j])||(p[j]=='?')){
    			i++;j++;
    			continue;
    		}
    		if (p[j]=='*') {
    			tmp = j;
    			j++;
    			tmps = i;
    			continue;
    		}
    		if (tmp!=-1){
    			j = tmp+1;
    			i = ++tmps;
    			continue;
    		}
    		return false;
    	}
    	while ((j<p.length())&&(p[j]=='*'))
    		j++;
    	if (j==p.length())
    		return true;
    	else 
    		return false;
        
    }
};
