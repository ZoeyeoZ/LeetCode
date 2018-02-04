/*
F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]
F(k-1) = 0 * Bk-1[0] + 1 * Bk-1[1] + ... + (n-1) * Bk-1[n-1]
       = 0 * Bk[1] + 1 * Bk[2] + ... + (n-2) * Bk[n-1] + (n-1) * Bk[0]
=>
F(k) - F(k-1) = Bk[1] + Bk[2] + ... + Bk[n-1] - (n-1)Bk[0]
              = (Bk[0] + ... + Bk[n-1]) - nBk[0]
              = sum - nBk[0]
k = 0; B[0] = A[0];
k = 1; B[0] = A[len-1];
k = 2; B[0] = A[len-2];
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
    	int sum = 0, l = A.size();
    	int iniS = 0;
    	for (int i=0; i<l; i++){
    		iniS += i*A[i];
    		sum += A[i];
    	}
    	int ans = iniS;
    	for (int i=l-1;i>=1;i--){
    		iniS += sum-l*A[i];
    		ans = max(ans, iniS);
    	}
        return ans;
    }
};
// int sum = accumulate(A.begin(), A.end(), 0);