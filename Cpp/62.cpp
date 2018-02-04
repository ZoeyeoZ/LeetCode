// C(m,m+n) = (m+n)!/(m!*n!) = (m+n)(m+n-1)...(m+1)/n!
// m>n
class Solution {
public:
    int uniquePaths(int m, int n) {
    	if (m==1 || n==1)
    		return 1;
    	m--;
    	n--;
    	if (m<n)
    		swap(m,n);
    	long ans = 1;
    	int i = m+1, j =1;
    	for (; i<=m+n;i++,j++){
    		ans *= i;
    		ans /= j;
    	}
    	return ans;
        
    }
};