class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	unordered_map<char,int> pm;
    	unordered_map<string,int> sm;
    	istringstream in(str);
    	int i=0, l = pattern.length();
    	for (string s; in>>s; i++){
    		if (i==l || pm[pattern[i]]!=sm[s])
    			return false;
    		pm[pattern[i]] = sm[s] = i+1; //not i, in case of 0
    	}
        return i==l;
    }
};
/*
// abba, dog dog dog dog should return flase, but it returns true;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	unordered_map<char,string> m;
    	int i=0,j, l=pattern.length();
        char p;
        string s;
    	for (int k=0;k<l;k++){
    		if (i>=str.length())
    			return false;
    		j = str.find(" ",i);
            if (j==-1)
                j = str.length();
            p = pattern[k];
            s = str.substr(i,j-i);
    		if (m.find(p)!=m.end() && m[p]!=s)
    			return false;
    		else
    			m[p] = s;
    		i = j+1;
    	}  
    	return true;   
    }
};