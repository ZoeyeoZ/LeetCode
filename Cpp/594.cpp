class Solution {
public:
    int findLHS(vector<int>& nums) {
    	unordered_map<int, int> M;
    	for (auto num:nums)
    		M[num]++;
    	int ans = 0;
    	for (auto it:M)
    		if (M.count(it.first-1) > 0)
    			ans = max(ans, it.second + M[it.first-1]);
    	return ans;
    }
};