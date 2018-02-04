/*
LUS
A!=B, A.len>=B.len
=>
Sort
longest: uniqiue && not a subsequence of the strings with the length larger than it
*/
/*
class Solution {
public:
	bool isSub(string s1, string s2){
		if (s1==s2)
			return true;
		int i = 0;
		for (int j=0; j<s2.length() && i<s1.length(); j++)
			if (s1[i]==s2[j])
				i++;
		return i == s1.length();
	}
    int findLUSlength(vector<string>& strs) {
    	auto comp = [](const string s1, const string s2){
    		return s1.length()==s2.length() ? s1.compare(s2) : s1.length()-s2.length();
    	};
    	sort(strs.begin(),strs.end(),comp);
    	for (int i=strs.size()-1; i>=0; i--)
    		if ((i>0 && strs[i]!=strs[i-1]) || i==0){
	    		int j = i+1;
	    		for (;j<strs.size();j++)
	    			if (isSub(strs[i],strs[j]))
	    				break;
	    		if (j==strs.size())
	    			return strs[i].length();
	    	}
    	return -1; 
    }
};
//terminate called after throwing an instance of 'std::bad_alloc'
//  what():  std::bad_alloc
*/
class Solution {
public:
	bool isSub(string s1, string s2){
		if (s1==s2)
			return true;
		int i = 0;
		for (int j=0; j<s2.length() && i<s1.length(); j++)
			if (s1[i]==s2[j])
				i++;
		return i == s1.length();
	}
    int findLUSlength(vector<string>& strs) {
    	unordered_map<string,int> m;
    	for (int i=0; i<strs.size(); i++)
    		m[strs[i]]++;
    	vector<pair<string,int>> v;
    	for (auto it=m.begin(); it!=m.end();it++)
    		v.push_back(*it);
    	auto comp = [](pair<string,int>& a, pair<string,int>& b){
    		return a.first.size()>b.first.size();
    	};
    	sort(v.begin(),v.end(),comp);
    	for (int i=0; i<v.size();i++)
    		if (v[i].second==1){
    			int j=0;
    			for (;j<i;j++)
    				if (isSub(v[i].first,v[j].first))
    					break;
    			if (i==j)
    				return v[i].first.size();
    		}
    	return -1; 
    }
};