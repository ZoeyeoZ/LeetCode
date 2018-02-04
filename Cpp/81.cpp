class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	if (nums.empty())
    		return false;
    	int l = 0, len = nums.size(), r = len-1, m;
    	while (l<r){
    		m = (l+r)/2;
    		if (nums[m]==target)
    			return true;
    		if (nums[m]>nums[r])//l..up..mid..largest,smallest..r
    			if (nums[m]>target && nums[l]<= target) // l.[.up.].mid..largest,smallest..r
    				r = m;
    			else 
    				l = m+1;
    		else if (nums[m]<nums[r]) //l..largest,smallest..up..mid..up..r
    			if (nums[m]<target && nums[r]>= target) //l..largest,smallest..up..mid.[.up.].r
    				l = m+1;
    			else 
    				r = m;
    		else r--; // l..m.largeest,smallest.r || l..largeest,smallest..m..r

    	}
    	return nums[l] == target ? true:false;    
    }
};