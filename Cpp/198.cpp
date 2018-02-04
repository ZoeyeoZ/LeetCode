class Solution {
public:
    int rob(vector<int>& nums) {
    	int n = nums.size();
    	int a1 = 0, a2 = 0;
    	for (int i=0; i<n; i++)
    		if (i%2==0)
    			a1 = max(a1+nums[i],a2);
    		else 
    			a2 = max(a2+nums[i],a1);
    	return max(a1,a2);
    }
};