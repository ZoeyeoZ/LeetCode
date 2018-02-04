//Combination Sum
// f(n,T) = f(n-1,T-k*j) + k*j
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
 		vector<int> candidates={1,2,3,4,5,6,7,8,9};
        vector<vector<vector<int>>>  dp;
    	for (int i = 0; i<target;i++){
    		vector<vector<int>> row;
    		dp.push_back(row);
    	}
    	for (int i=0; i<9; i++){
    		if (candidates[i]>target)
    			continue;
            for (int j = target-candidates[i]; j>=1; j--){
    			for (auto num:dp[j-1])
    				if (num.size()<k){
    					vector<int> tmp = num;
    					tmp.push_back(candidates[i]);
    					dp[j+candidates[i]-1].push_back(tmp);
    				}
    		}
            dp[candidates[i]-1].push_back({candidates[i]});
    	}
        if (dp[target-1].empty())
            return dp[target-1];
        //sort (dp[target-1].begin(), dp[target-1].end());
        //return dp[target-1];
        vector<vector<int>> ans;
        for (auto num:dp[target-1])
            if (num.size() == k)
                ans.push_back(num);
    	return ans;

    }
};