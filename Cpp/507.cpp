class Solution {
public:
    bool checkPerfectNumber(int num) {
    	int k = sqrt(num);
    	int s = (k*k==num ? -k+1:1);
    	for (int i=2;i<=k;i++)
    		if (num%i==0)
    			s += i + num/i;
    	return s==num;
    }
};