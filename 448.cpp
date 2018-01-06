// using negation as mark
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	for (int i=0;i<nums.size();i++){
    		int n = abs(nums[i]);
    		if (nums[n-1]>0)
    			nums[n-1] *= -1;
    	}
    	vector<int> ans;
    	for (int i=0;i<nums.size();i++)
    		if (nums[i]>=0)
    			ans.push_back(i+1);
    	return ans;
    }
};