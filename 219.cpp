// nums[i]=[j] & |i-j|<=k
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	set<int> number;
    	for (int i=0; i<nums.size();i++){
    		if (i>k)
    			number.erase(nums[i-k-1]);
    		if (!number.insert(nums[i]).second) // same number
    			return true;
    	}
    	return false;
    }
};