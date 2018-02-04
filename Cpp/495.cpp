class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	int ans = 0, p = 0;
    	for (auto t:timeSeries){
    		ans += duration - (t<p ? p-t:0);
    		p = t+duration;
    	}
    	return ans;
    }
};