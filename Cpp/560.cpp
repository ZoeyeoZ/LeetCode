class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int,int> M;
    	int ans = 0, sum = 0;
    	M[0] = 1;
    	for (auto num:nums){
    		sum += num;
    		ans += M[sum-k];
    		M[sum]++;
    	}
    	return ans;
    }
};