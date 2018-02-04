class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
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
    		if (nums[i]==nums[j])
    			continue;
		    nums[i] ^= nums[j];
		    nums[j] ^= nums[i];
		    nums[i] ^= nums[j];
    		helper(nums, ans, i+1);
    		/* avoid next same number be used.
    		such as 1122
    		(1122,1),(2112,2), then the next 2 will not be used.
    		*/
    		/*nums[i] ^= nums[j];
		    nums[j] ^= nums[i];
		    nums[i] ^= nums[j];*/
    	}

    }

};