/*
https://leetcode.com/problems/super-pow/discuss/

1337 = 7*191
p(1337) = p(7)*p(191) = 6*190 = 1140

a = 7^nx
b = 1140p+q
a^b % 1337
=((7^{1140np+nq} % 1337) * (x^{1140p+q} % 1337) ) % 1337
=((7^{1140np+nq} % 1337) * (x^q % 1337) ) % 1337
=(7*(7^{1140np+nq-1} % 191) * (x^q % 1337) ) % 1337
=(7*(7^{nq-1} % 191) * (x^q % 1337) ) % 1337
=((7^{nq} % 1337) * (x^q % 1337) ) % 1337
=((7^{nq}*x^q % 1337)
=((7^n*x)^q % 1337
= a^q % 1337
*/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
    	a %= 1337;
        if (a==0)
        	return 0;

        int p = 0;
        for (auto i:b)
        	p = (p*10+i)%1140;
        p = (p==0 ? 1140:p);

        int ans = 1;
        while (p!=0){
        	if ((p&1)!= 0) 
        		ans = ans*a%1337;
	        a = a*a%1337;
	        p >>= 1;
        }
        return ans;
    }
};