/*
//(i,j), i=j.rev.sub && j.rev.rest is P/single
i.left,i.right,j=i.left.rev && i.right is P
i=j.right.rev,j.left,j.right && j.left is P

Edge case - ""
*/
class Solution {
public:
	bool isP(string s){
		int i = 0, j = s.length()-1;
		while (i<j)
			if (s[i++]!=s[j--])
				return false;
		return true;
	}
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> wmap;
        vector<vector<int>> ans;
        for (int i=0;i<words.size();i++){
        	string word = words[i];
        	reverse(word.begin(),word.end());
        	wmap[word] = i;
        }
        //""
        if (wmap.find("")!=wmap.end())
        	for (int i=0;i<words.size();i++)
        		if (words[i]!="" && isP(words[i]))
        			ans.push_back({wmap[""],i});
        for (int i=0;i<words.size();i++){
        	string word = words[i];
        	for (int j=0;j<word.size();j++){
        		string left = word.substr(0,j);
        		string right = word.substr(j);
        		if (wmap.find(left)!=wmap.end() && wmap[left]!=i && isP(right))
        			ans.push_back({i,wmap[left]});
        		if (wmap.find(right)!=wmap.end() && wmap[right]!=i && isP(left))
        			ans.push_back({wmap[right],i});
        	}
        }
        return ans;
    }
};
//213ms
/*
//103ms
class Solution {
public:
	bool isPalin(string& w, int i1, int i2) {
		for (; i1 < i2; i1++, i2--)
			if (w[i1] != w[i2]) return false;
		return true;
	}
    vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> ht;
		for (int i=0; i < words.size(); i++) ht[words[i]] = i;
		vector<vector<int>> ret;
		for (int i=0; i < words.size(); i++) {
			auto w=words[i];
			reverse(w.begin(), w.end());
			int n=w.size();
			if (ht.count(w) && ht[w] != i) { ret.push_back({ht[w], i});  }
			if (n && isPalin(w, 0, n-1) && ht.count("")) { ret.push_back({i, ht[""]}); ret.push_back({ht[""], i});}
			for (int l=1; l < n; l++) {
				if (isPalin(w, 0, n-l-1) && ht.count(w.substr(n-l)) && ht[w.substr(n-l)]!=i) ret.push_back({i, ht[w.substr(n-l)]});
				if (isPalin(w, l, n-1) && ht.count(w.substr(0, l)) && ht[w.substr(0, l)] != i) ret.push_back({ht[w.substr(0, l)], i});
			}
		}
		return ret;
    }
};
*/