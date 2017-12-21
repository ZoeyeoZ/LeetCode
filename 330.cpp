class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    	int cnt = 0, i = 0, l = nums.size();
    	long m = 0;
    	while (m<n){
    		if (i<l && nums[i]<=m+1)
    			m += nums[i++];
    		else{
    			m += m + 1;
    			cnt++;
    		}

    	}
    	return cnt;
    }
};