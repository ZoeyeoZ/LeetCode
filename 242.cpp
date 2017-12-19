class Solution {
public:
    bool isAnagram(string s, string t) {
    	int l1=s.length();
    	if (l1!=t.length())
    		return false;
    	vector<int> cnt(256,0);
    	for (char ch:s)
    		cnt[ch]++;
    	for (char ch:t){
    		cnt[ch]--;
    		if (cnt[ch]<0)
    			return false;
    	}
    	return true;
    }
};