class Solution {
public:
    string customSortString(string S, string T) {
    	vector<int> sMap(26,0);
    	string res = "";
    	for (char c:T)
    		++ sMap[c-'a'];
    	for (char c:S){
    		while (sMap[c-'a']>0){
    			res += c;
    			sMap[c-'a']--;
    		}
    	}
    	for (int i = 0; i < 26; ++ i)
    		while (sMap[i]>0){
    			res += ('a'+i);
    			sMap[i]--;
    		}
    	return res;
    }
};