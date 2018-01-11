class Solution {
public:
    int largestPalindrome(int n) {
    	if (n==1)
    		return 9;
    	int r = pow(10,n)-1, l = pow(10,n-1);
    	for (int i=r;i>=l;i--){
    		string s = to_string(i);
    		reverse(s.begin(), s.end());
    		long tmp = stol(to_string(i)+s);
    		for (long j = r; j*j>=tmp;j--)
    			if (tmp%j==0 && tmp/j<=r)
    				return tmp%1337;
    	}
    	return -1;
    }
};