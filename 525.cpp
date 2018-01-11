//https://leetcode.com/problems/contiguous-array/discuss/99655
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	unordered_map<int,int> m;
        m[0]=0;
    	int sum = 0, maxL = 0;
    	for (int i=0; i<nums.size();i++){
    		sum += (nums[i]?1:-1);
    		if (m.find(sum)==m.end())
    			m[sum] = i+1;
    		else 
    			maxL = max(maxL,i+1-m[sum]);
    	}
    	return maxL;
    }
};
//152
/*92
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int dp[100001];
        int sum = 0, n = nums.size(), minv = 0, maxv = 0, ans = 0;
        dp[n] = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i]) sum++;
            else sum--;
            
            int j = sum + n;
            if (sum > maxv) dp[j] = i + 1, maxv++;
            else if (sum < minv) dp[j] = i + 1, minv--;
            else if (i + 1 - dp[sum + n] > ans) ans = i + 1 - dp[sum + n];
        }
        
        return ans;
    }
};*/