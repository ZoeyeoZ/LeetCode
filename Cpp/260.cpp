
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	int ab = 0;
    	vector<int> ans(2,0);
    	// ans = a ^ b;
    	for (int num : nums)
    		ab ^= num;
    	//since a!=b. there is one bit they are diff
    	ab &= -ab;
    	//seperate 
    	for (int num : nums)
    		if ((num & ab) == 0)
    			ans[0] ^= num;
    		else ans[1] ^= num;
    	return ans;
    }
};