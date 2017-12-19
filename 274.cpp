// h: at least h, N-h: at most h
// some bucket sort
class Solution {
public:
    int hIndex(vector<int>& citations) {
    	const int n = citations.size();
    	vector<int> cnt(n+1,0);
    	for (auto c:citations)
    		if (c>=n)
    			cnt[n]++;
    		else cnt[c]++;
    	int s = 0;//at lest i
    	for (int i = n;i>=0;i--){
    		s += cnt[i];
    		if (s >= i)
    			return i;
    	}
    	return 0;
    }
};