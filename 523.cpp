class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	unordered_set<int> s;
    	int sum = 0, pre = 0;
    	for (auto num:nums){
    		sum += num;
    		int mod = (k==0 ? sum:sum%k);
    		if (s.count(mod)) // (lasts-s)%k==0
    			return true;
    		s.insert(pre);
    		pre = mod;
    	}
    	return false;
    }
};