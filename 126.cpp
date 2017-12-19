//Memory Limt Exceeded

class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> Aset;
    string begin;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_map<string,int> Wset;
        begin = beginWord;
    	for (string word:wordList)
            if (word!=beginWord)
    		  Wset[word]=INT_MAX;
    	if (Wset[endWord]!=INT_MAX)
    		return ans;
        Aset[beginWord] = {};
    	set<string> beg = {beginWord};
        int l = 0;
    	while (!beg.empty()){
    		set<string> tmp;
    		for (string word:beg){
    			for (int i=0;i<word.length();i++)
    				for (char c = 'a';c<='z';c++){
    					string ss = word;
    					ss[i]=c;
    					if (Wset[ss]>l){
                            Aset[ss].push_back(word);
    						Wset[ss] = l+1;
    						tmp.insert(ss);
    					}
    					
    				}
    		}
    		beg = tmp;
    		l ++;
    	}
        vector<string> curp = {endWord};
        vector<string> res = {};
        helper(res,curp);
        return ans;
    }
    void helper(vector<string> res, vector<string> curp){
        for (auto ss:curp){
            res.insert(res.begin(),ss);
            if (ss==begin)
                ans.push_back(res);
            else 
                helper(res,Aset[ss]);
            res.erase(res.begin());
        }
    }
};