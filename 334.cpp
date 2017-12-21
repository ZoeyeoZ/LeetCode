class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	int n = nums.size();
    	if (n==0)
            return false;
    	vector<int> snums(n,0), lnums(n,0);
    	snums[0] = nums[0];
    	for (int i=1;i<n;i++)
    		snums[i] = min(snums[i-1],nums[i]);
    	lnums[n-1] = nums[n-1];
    	for (int i=n-2;i>=0;i--){
    		lnums[i] = max(lnums[i+1],nums[i]);
    		if (snums[i]<nums[i] && nums[i]<lnums[i])
    			return true;
    	}
    	return false;
    }
};
//6ms
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};
*/