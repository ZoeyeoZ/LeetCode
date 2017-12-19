class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> ans;
    	helper(nums, ans, 0);
    	return ans;
    }
    void helper(vector<int> nums, vector<vector<int>> &ans, int i){
    	if (i==nums.size()){
    		ans.push_back(nums);
    		return;
    	}
    	helper(nums, ans, i+1);
    	for (int j=i+1; j<nums.size();j++){
		    nums[i] ^= nums[j];
		    nums[j] ^= nums[i];
		    nums[i] ^= nums[j];
    		helper(nums, ans, i+1);
    		nums[i] ^= nums[j];
		    nums[j] ^= nums[i];
		    nums[i] ^= nums[j];
    	}

    }

};