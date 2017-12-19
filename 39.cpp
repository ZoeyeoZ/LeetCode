//Combination Sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<vector<int>>>  dp;
    	for (int i = 0; i<target;i++){
    		vector<vector<int>> row;
    		dp.push_back(row);
    	}

    	for (int i=0; i<candidates.size(); i++){
    		if (candidates[i]>target)
    			continue;
    		dp[candidates[i]-1].push_back({candidates[i]});
    		for (int k = 1; k<=target-candidates[i]; k++){
    			for (auto num:dp[k-1]){
    					vector<int> tmp = num;
    					tmp.push_back(candidates[i]);
    					dp[k+candidates[i]-1].push_back(tmp); // so candidate can be used many time
    				}
    		}
    	}
    	return dp[target-1];

    }
};