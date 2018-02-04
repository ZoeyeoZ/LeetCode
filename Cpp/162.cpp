//there must exist one in the larger side
class Solution {
public:
	int helper(vector<int> nums, int l, int r){
		int m = (l+r)/2;
		if (nums[m]>nums[m-1] || m==0)
			if (nums[m]>nums[m+1] || m==nums.size()-1)
				return m;
			else return helper(nums,m+1,r);
		else return helper(nums,l,m-1);

	}
    int findPeakElement(vector<int>& nums) {
    	return helper(nums,0,nums.size()-1);
    }
};