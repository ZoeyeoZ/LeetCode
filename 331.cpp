class Solution {
public:
    bool isValidSerialization(string preorder) {
    	if (preorder=="#")
            return true;
    	istringstream iss(preorder);
    	stack<int> st;
    	string s;

    	while (getline(iss,s,',')){
    		if(s == "#" && st.empty()) 
    			return false;
            if(!st.empty()){ 
            	st.top()++;
            	if (st.top()==2)
            		st.pop();
            }
            if(s != "#") st.push(0);
            if(st.empty() && !iss.eof()) 
            	return false;
    	}
        return st.empty();
    }
};