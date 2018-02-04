/*
s=122
p = 2, -> num*2
p = 1, -> num*1
*/
class Solution {
public:
    int magicalString(int n) {
    	if (n==0)
    		return 0;
    	if (n<=3)
    		return 1;
    	vector<int> a(n,0);
    	a[0] = 1, a[1] = 2, a[2] = 2;
    	int ans = 1, m = 3, p = 2, num = 2;
    	while (m<n){
    		num ^= 3;
    		if (num==1)
    			ans += min(a[p],n-m);
			for (int i=0; i<a[p] && m<n;i++,m++)
    				a[m] = num;
    		p++;
    	}
    	return ans;
    }
};