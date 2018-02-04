class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_map<string,int> Wset;
    	for (string word:wordList)
    		Wset[word]=INT_MAX;
    	if (Wset[endWord]!=INT_MAX)
    		return 0;
    	set<string> beg = {beginWord};
    	set<string> end = {endWord};
    	int l = 1;
    	while (!beg.empty() && !end.empty()){
    		set<string> tmp;
    		if (beg.size()>end.size()){
    			tmp = beg;
    			beg = end;
    			end = tmp;
    			tmp = beg;
    		}
    		for (string word:beg){
    			for (int i=0;i<word.length();i++)
    				for (char c = 'a';c<='z';c++){
    					string ss = word;
    					ss[i]=c;
    					if (end.count(ss)>0)
    						return l+1;
    					if (Wset[ss]>l){
    						Wset[ss] = l+1;
    						tmp.insert(ss);
    					}
    					
    				}
    		}
    		beg = tmp;
    		l ++;
    	}
    	return 0;
    }
};