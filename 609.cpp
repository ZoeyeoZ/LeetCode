class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
    	unordered_map<string, vector<string>> M;
    	vector<vector<string>> ans;
    	for (auto path:paths){
    		string root, s;
    		istringstream iss(path);
    		getline(iss, root, ' ');
    		while (getline(iss, s, ' ')){
    			string f = root + '/' + s.substr(0, s.find('('));
    			string c = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
    			M[c].push_back(f);
    		}
    	}
    	for (auto it:M)
    		if (it.second.size()>1)
   				ans.push_back(it.second);
    	return ans;
    }
};