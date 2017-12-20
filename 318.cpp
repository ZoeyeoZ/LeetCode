class Solution {
public:
    int maxProduct(vector<string>& words) {
    	unordered_map<int,int> wl;//word and its maxinimum length
    	int ans = 0;
    	for (string word:words){
    		int mask = 0;
    		for (char ch:word)
    			mask |= 1<<(ch-'a');
    		wl[mask] = max(wl[mask],(int)word.size());
    		for (auto p:wl)
    			if (!(mask&p.first))
    				ans = max(ans,(int)word.size()*p.second);
    	}
    	return ans;
        
    }
};