// Divide Two Integers
/*
bit
^ xor, not same = 1 = true;
<< *2
*/
typedef long long ll;
class Solution{
public:
	int divide(int dividend, int divisor){
		// INT_MIN = -2147483648, INT_MAX = 2147483647, abs(INT_MIN) = -2147483648
		if ((!divisor)||((dividend == INT_MIN) && (divisor == -1)))
			return INT_MAX;
		int sig = ((dividend<0)^(divisor<0)) ? sig = -1:1;
		ll ans = 0, dd = labs(dividend), ds = labs(divisor);
		//! labs, not abs
		ll tmp, k;
		while (dd>=ds){
			tmp = ds;
			k = 1;
			while (dd > (tmp<<1)){
				tmp <<= 1;
				k <<= 1;
			}
			dd -= tmp;
			ans +=k;
		}
		return sig==1? ans : -ans;
	}
};