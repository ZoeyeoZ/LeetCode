/*
DP,O(n*sqrt(n))
if i%k ==0, 
	dp[i] = min(dp[i/k]+k,dp[i])
if k=ab,
	since a+b<=ab, dp[i] = min(dp[i/k]+a+b,dp[i]), copy i/k and paste a-1 times, copy i/b, paste b-1 time
		
		int ans = k;
        for (int i = 2; i <= sqrt(k); i++) {
            if (k%i == 0) {
                ans = min(ans, helper(dp, i)+k/i);
                ans = min(ans, helper(dp, k/i)+i);
            } 
        }
        dp[k] = ans;

=> greedy,O(sqrt(n))


*/
class Solution {
public:
    int minSteps(int n) {
    	int ans = 0;
    	for (int i = 2; i <= sqrt(n); i++)
    		while (n%i == 0){
    			ans += i;
    			n /= i;
    		}
    	if (n>1) return ans+n;
    	return ans;
    }
};