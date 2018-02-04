class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	if (nums.size()==0)
    		return 0;
    	int n = nums.size();
    	int cur = (nums[0]==1 ? 1:0);
    	int ans = cur;
    	for (int i=1;i<n;i++)
    		if (nums[i]==0)
    			cur = 0;
    		else{
    			cur++;
    			ans = max(ans,cur);
    		}
        return ans;
    }
};