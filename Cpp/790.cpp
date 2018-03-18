/*
n>=4
|_ _|
4->11,5->24
*/
class Solution {
public:
    int numTilings(int N) {
    	int mod = 1000000007;
    	long n[4] = {1,1,2,0};
    	if (N<3)
    		return n[N];
    	for (int i=3; i<=N; i++){
    		n[3] = ((n[2]*2 %mod) + n[0])%mod;
    		n[0] = n[1];
    		n[1] = n[2];
    		n[2] = n[3];
    	}
    	return n[3];
    }
};
/*
public int numTilings(int n) {
	        int mod = 1000000007;
	        long[] dp = new long[4];
	        dp[0] = 1;
	        for(int i = 0;i < n;i++){
	        	long[] ndp = new long[4];
	        	// ||
	        	ndp[3] += dp[0];
	        	// |
	        	ndp[1] += dp[2];
	        	ndp[2] += dp[1];
	        	// none
	        	ndp[0] += dp[3];
	        	// -
	        	ndp[0] += dp[0];
	        	
	        	ndp[1] += dp[0];
	        	ndp[2] += dp[0];
	        	ndp[3] += dp[1];
	        	ndp[3] += dp[2];
	        	
	        	for(int j = 0;j < 4;j++){
	        		dp[j] = ndp[j] % mod;
	        	}
	        }
	        return (int)dp[0];
	    }
	    */

/*
We can make a new even row from the previous even row and a horizontal domino, 
	or the even row before that add 2 vertical dominos, 
	or the previous odd row and a tromino.
We can make a new odd row from the previous odd row and a vertical domino, 
	or the i - 2 even row and a tromino in 2 possible orientations.

def numTilings(self, N):
        MOD = (10 ** 9) + 7

        even = [0, 1, 2, 5]
        odd = [0, 0, 2, 4]

        for i in range(4, N + 1):

            new_even = (even[i - 1] + even[i - 2] + odd[i - 1]) % MOD
            even.append(new_even)

            new_odd = (odd[i - 1] + 2 * even[i - 2]) % MOD
            odd.append(new_odd)

        return clean[N] % MOD