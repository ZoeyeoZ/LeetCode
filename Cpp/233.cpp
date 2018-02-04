//233. Number of Digit One
/*
n=ABCDEF
eg. m=100, a=ABCD,b=EF
if D>1,
000100~AB(C-1)100
if D==1,
ABC100~ABC1EF
*/
class Solution {
public:
    int countDigitOne(int n) {
    	int ans = 0;
    	for (long long m=1;m<=n;m*=10)
    		ans += (n/m+8)/10*m + (n/m%10 == 1)*(n%m+1);
    	return ans;   
    }
};

