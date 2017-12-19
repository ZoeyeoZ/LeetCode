//getline(ss,tmp,'/') acts like Java's split
class Solution {
public:
    string simplifyPath(string path) {
    	stringstream ss(path);
    	string tmp, ans = "";
    	vector<string> res;
    	while (getline(ss,tmp,'/')){
    		if (tmp == "" or tmp ==".") 
    			continue;
    		if (tmp == ".."){
    			if (!res.empty())
    				res.pop_back();
    		}
    		else res.push_back(tmp);
    	}
    	for (auto str:res)
    		ans += '/'+str;
    	return ans=="" ? "/":ans;
        
    }
};