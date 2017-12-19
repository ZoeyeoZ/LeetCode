class NumArray {
public:
	vector<int> ans;
    NumArray(vector<int> nums) {
    	int l = nums.size();
    	ans.push_back(0);
    	for (int i=0;i<l;i++)
    		ans.push_back(ans[i]+nums[i]);
    }
    
    int sumRange(int i, int j) {
    	return ans[j+1]-ans[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */