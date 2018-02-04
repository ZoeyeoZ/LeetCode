class Solution {
public:
	vector<string> ans;
	void helper(string s, string num, int target, int p, long val){
		if (p == num.length()){
			if (val==target)
				ans.push_back(s);
			return;
		}
		for (int i=p;i<num.length() && i<p+10;i++){ 
			// p+10,to make sure it < INT_MAX

			string s_ = num.substr(p,i-p+1);
			long val_ = stol(s_);
			if (p==0)
				helper(s+s_,num,target-val,i+1,val_);
			else{
				helper(s+"+"+s_,num,target-val,i+1,val_);	// t = v+v_
				helper(s+"-"+s_,num,target-val,i+1,-val_);// t = v-v_
				helper(s+"*"+s_,num,target,i+1,val*val_);	// t = v*v_
			}
			// in case of invalid num, such as 1*05. but 1*0+5 shoule be used.
			if (num[p]=='0')
				break;
		}

	}
    vector<string> addOperators(string num, int target) {
    	if (num.size()==0)
    		return ans;
    	helper("",num,target,0,0);
    	return ans;   
    }
};