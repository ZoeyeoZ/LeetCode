//Combination Sum
// f(n,T) = f(n-1,T-k*j) + k*j
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end()); 
        vector<vector<vector<int>>>  dp;
    	for (int i = 0; i<target;i++){
    		vector<vector<int>> row;
    		dp.push_back(row);
    	}

    	for (int i=0; i<candidates.size(); i++){
    		if (candidates[i]>target)
    			continue;
            for (int k = target-candidates[i]; k>=1; k--){
    			for (auto num:dp[k-1]){
    					vector<int> tmp = num;
    					tmp.push_back(candidates[i]);
    					dp[k+candidates[i]-1].push_back(tmp);
    				}
    		}
            dp[candidates[i]-1].push_back({candidates[i]});
    	}
        if (dp[target-1].empty())
            return dp[target-1];
        sort (dp[target-1].begin(), dp[target-1].end());
        vector<vector<int>> ans;
        ans.push_back(dp[target-1][0]);
        for (auto num:dp[target-1])
            if (num == ans.back())
                continue;
            else  ans.push_back(num);
    	return ans;

    }
};