class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> ans;
    	for (int i=0;i<n;i++){
    		auto k = lower_bound(ans.begin(),ans.end(),nums[i]);// >=nums[i] & smallest pos
    		if (k==ans.end())
    			ans.push_back(nums[i]);
    		else *k = nums[i];
    	}
        return ans.size();
    }
};