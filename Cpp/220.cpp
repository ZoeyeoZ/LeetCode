class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	set<long> number;
    	for (int i=0; i<nums.size();i++){
    		if (i>k)
    			number.erase(nums[i-k-1]);
    		// lower_bound(val): 返回容器中第一个大于或等于val的元素的iterator位置, x>= nums[i]-t ==> x-nums[i]>=-t
	        auto pos = number.lower_bound((long)nums[i] - t);
	        // &&  x - nums[i] <= t  ==> -t <= x - nums[i] <= t ==> |x - nums[i]| <= t 
	        if (pos != number.end() && (long)*pos - nums[i] <= t) return true;
	        number.insert(nums[i]);
    	}
    	return false;
    }
};