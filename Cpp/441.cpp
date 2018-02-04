class Solution {
public:
    int arrangeCoins(int n) {
    	int ans = 0;
    	while (n-ans>0){
    		ans++;
    		n -= ans;
    	}
        return ans;
    }
};
//29
/*12
class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return (int)((-1 + sqrt(1 + 8 * (long)n)) / 2);
    }
};
*/
/*
1+2+..+k
(1+k)*k/2 = n
k+kk = 2n
kk + k - 2n = 0;
(-1+sqrt(1-4*1*-2n))/2
(-1+sqrt(1+8n))/2
*/