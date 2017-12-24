//DP
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	int n = envelopes.size();
    	if (n==0)
    		return 0;
    	sort(envelopes.begin(),envelopes.end(),[](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);});
    	int ans = 1;
    	vector<int> dp(n+1,1);
    	for (int i=0;i<n;i++)
    		for (int j=0;j<i;j++)
    			if (envelopes[j].first<envelopes[i].first &&envelopes[j].second<envelopes[i].second){
    				dp[i] = max(dp[i],dp[j]+1);
    				ans = max(ans,dp[i]);
    			}

        return ans;
    }
};
//O(n^2)
/*
19ms
O(nlgn)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](pair<int,int> a, pair<int,int> b) {return (a.first < b.first) || (a.first == b.first && a.second > b.second);});
        int n = envelopes.size();
        vector<int> tails;
        for (int i = 0; i < n; i++) {
            int low = 0, high = tails.size();
            while (low < high) {
                int mid = low + (high-low)/2;
                if (tails[mid] < envelopes[i].second)
                    low = mid+1;
                else
                    high = mid;
            }
            if (low == tails.size()) 
                tails.push_back(envelopes[i].second);
            else
                tails[low] = envelopes[i].second;
        }
        return tails.size();
    }
};
*/