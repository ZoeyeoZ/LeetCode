/*Time....
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	int l = s.length(), n = wordDict.size();
    	if (n==0)
    		return {};
    	vector<vector<string>> ans(l+1,vector<string>());
    	ans[0] = {""};
    	unordered_map<string,int> Wmap;
    	for (int j=0;j<n;j++)
    		Wmap[wordDict[j]] = 1;
    	for (int i=1;i<=l;i++)
    		for (int j=0;j<i;j++)
    			if (ans[j].size()>0 && Wmap[s.substr(j,i-j)])
    				for (string tmp:ans[j]){
    					if (tmp=="")
    						ans[i].push_back(tmp+s.substr(j,i-j));
    					else
    						ans[i].push_back(tmp+" "+s.substr(j,i-j));
    					cout << tmp+" "+s.substr(j,i-j) <<endl;
    				}
    	
        return ans[l];
    }
};
*/
class Solution {
public:
	unordered_map<string,vector<string>> Wmap;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	Wmap[""] = {""};
    	return helper(s, wordDict);
    }
    vector<string> helper(string s, vector<string>& wordDict){
    	if (Wmap.find(s)!=Wmap.end())
    		return Wmap[s];
    	set<string> anstmp;
    	vector<string> ans;
    	for (string word : wordDict) 
    		if (s.substr(0,word.length())==word){
    			vector<string> tmp = helper(s.substr(word.length()),wordDict);
    			for (auto ss:tmp){
    				anstmp.insert(word + (ss==""? "":" ")+ ss);
    				//cout <<word + " " + ss <<endl;
    			}
    		}
    	for (auto ss:anstmp)
    		ans.push_back(ss);
    	Wmap[s] = ans;
    	return ans;

    }
};
