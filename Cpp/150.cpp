class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	int ans = 0, l = tokens.size();
    	if (l==0)
    		return ans;
    	stack<int> st;
    	int i = 0, a, b, k;
    	unordered_map<string,int> Omap;
    	Omap["+"] = 0,Omap["-"] = 1, Omap["*"] = 2, Omap["/"] = 3; 
    	while (i<l){
    		a = 0, b = 1, k = 0;
    		if (tokens[i].length()>1 || (tokens[i][0]<='9'&&tokens[i][0]>='0')){
    			if (tokens[i][0]=='-' || tokens[i][0]=='+'){
    				b= tokens[i][0]=='-'?-1:1;
    				k=1;
    			}
				for (; k<tokens[i].size(); k++)
				    if (tokens[i][k]<='9'&&tokens[i][k]>='0')
				    	a = a*10+(tokens[i][k]-48);
				st.push(a*b);
    		}
    		else
    			switch (Omap[tokens[i]]){
    				case 0:
    					a = st.top();
    					st.pop();
    					b = st.top();
    					st.pop();
    					st.push(b+a);
    					break;
    				case 1:
    					a = st.top();
    					st.pop();
    					b = st.top();
    					st.pop();
    					st.push(b-a);
    					break;
    				case 2:
    					a = st.top();
    					st.pop();
    					b = st.top();
    					st.pop();
    					st.push(b*a);
    					break;
    				case 3:
    					a = st.top();
    					st.pop();
    					b = st.top();
    					st.pop();
    					st.push(b/a);
    					break;
    			}
    		i++;
    	}
    	return st.top();
    }
};