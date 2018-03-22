class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    	int n = nums.size();
    	vector<long> presum(n,0);
    	long sum = 0;
        for (int i = 0; i < n; ++i){
        	if (i>=k){
        		presum[i-k] = sum;
        		sum -= nums[i-k];
        	}
        	sum += nums[i];
        }
        presum[n-k] = sum;
        vector<int> maxFL(n,0), maxFR(n,0);
        sum = 0; int idx = 0;
        for (int i = 0; i <= n-3*k; ++i){
        	if (presum[i] > sum){
        		sum = presum[i];
        		idx = i;
        	}
        	maxFL[i] = idx;
        }
        sum = 0; idx = 0;
        for (int i = n-k; i >= 2*k; --i){
			if (presum[i] > sum){
        		sum = presum[i];
        		idx = i;
        	}
        	maxFR[i] = idx;
        }
        sum = 0; idx = 0;
        for (int i = k; i <= n-2*k; ++i){
        	long tmp = presum[maxFL[i-k]]+presum[i]+presum[maxFR[i+k]];
        	if (tmp > sum){
        		sum = tmp;
        		idx = i;
        	}
        }   
        return {maxFL[idx-k], idx, maxFR[idx+k]};
    }
};