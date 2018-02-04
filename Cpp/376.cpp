class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n<=1)
        	return n;
        vector<int> dp1(n,0);//positive
        vector<int> dp2(n,0);//negative
        dp1[0] = dp2[0] =1;
        for (int i=1;i<n;i++){
        	if (nums[i-1]<nums[i]){
        		dp1[i] = dp2[i-1]+1;
        		dp2[i] = dp2[i-1];
        	}
        	else if (nums[i-1]>nums[i]){
        		dp2[i] = dp1[i-1]+1;
        		dp1[i] = dp1[i-1];
        	}
        	else{
        		dp1[i] = dp1[i-1];
        		dp2[i] = dp2[i-1];
        	}
        }
        return max(dp1[n-1],dp2[n-1]);
    }
};
/*
O(1) space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int pos = 1, neg = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                pos = neg + 1;
            } else if (nums[i] < nums[i - 1]) {
                neg = pos + 1;
            }
        }
        return max(pos, neg);
    }
};*/