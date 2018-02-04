class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int l = 0, len = nums.size(), r = len-1, m, rm;
    	// find smallest
    	while (l<r){
    		m = (l+r)/2;
    		if (nums[m]>nums[r])
    			l = m+1;
    		else r = m;
    	}
    	int k = l;
    	l = 0, r = nums.size()-1;
    	while (l<=r){
    		m = (l+r)/2;
    		rm = (m+k)%len;
    		if (nums[rm] == target)
    			return rm;
    		if (nums[rm]<target)
    			l = m +1;
    		else r = m-1;
    	}
    	return -1;

        
    }
};