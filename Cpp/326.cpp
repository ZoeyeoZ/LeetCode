//Could you do it without using any loop / recursion?
class Solution {
public:
    bool isPowerOfThree(int n) {
    	//n=3^k => log(n)/log(3) is integer
    	//Returns the floating-point remainder of numer / denom (rounded towards zero)
        return fmod(log10(n)/log10(3),1)==0;
    }
};