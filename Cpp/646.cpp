/*
dp[i] = max(dp[j]+1), if p[j][1]<p[i][0], j<i
sort
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    	if (pairs.size()==1)
    		return 1;
    	vector<int> dp(pairs.size(),1);
    	int ans = 1;
    	auto comp = [](const vector<int>& p1, const vector<int>& p2){
    		return (p1[0]<p2[0]) || (p1[0]==p2[0] && p1[1]<p2[1]);
    	};
    	sort(pairs.begin(),pairs.end(),comp);
    	for (int i = 0; i < pairs.size(); i++)
    		for (int j = 0; j < i; j++)
    			if (pairs[j][1]<pairs[i][0]){
    				dp[i] = max(dp[j]+1,dp[i]);
    				ans = max(dp[i],ans);
    			}
    	return ans;
    }
};
/*
greedy
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [](const vector<int>& a, const vector<int>&b){
            return a[0] < b[0];
        };
        sort(pairs.begin(), pairs.end(), cmp);
        int count = 0, end = INT_MIN;
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] > end) {
                end = pairs[i][1];
                count++;
            }
            else if (pairs[i][1] < end){ // since it's later than end's [0], so it can must be added
                end = pairs[i][1];
            }
        }
        return count;
    }
};*/
