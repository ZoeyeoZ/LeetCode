class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    	int m =nums.size(), n = nums[0].size(), all = m*n;
    	if (r*c!=all)
    		return nums;
    	vector<vector<int>> ans(r,vector<int>(c,0));
    	for (int i=0;i<all;i++)
    		ans[i/c][i%c] = nums[i/n][i%n];
    	return ans;
    }
};