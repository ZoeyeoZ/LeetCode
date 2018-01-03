/*
sequence(P,Q): A[p],A[p+1],..A[Q]
dp[i]=d[i-1]+1, if A[i]-A[i-1]==A[i-1]-A[i-2]*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	int n = A.size();
    	if (n<3)
    		return 0;
    	vector<int> dp(n,0);
    	if (A[2]-A[1]==A[1]-A[0])
    		dp[2] = 1;
    	int ans = dp[2];
    	for (int i=3;i<n;i++)
    		if (A[i]-A[i-1]==A[i-1]-A[i-2]){
    			dp[i] = dp[i-1]+1;
    			ans += dp[i];
    		}
        return ans;
    }
};
//3
/*0
class Solution {
public:
    int numofsubstring(int n) {
        return (n - 1) * (n - 2) / 2;
        
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int prev = A[1] - A[0], i = 2;
        int res = 0;
        while (i < A.size()) {
            int cur = A[i] - A[i - 1];
            if (cur == prev) {
                int tmp_count = 3;
                i++;
                while (i < A.size() && (A[i] - A[i-1]) == prev) {
                    prev = A[i] - A[i-1];
                    tmp_count++;
                    i++;
                }
                res += numofsubstring(tmp_count);
                if (i < A.size()) {
                    cur = A[i] - A[i-1];
                }
            }
            else {
                prev = cur;
                i++;
            }
        }
        return res;
    }
};
*/