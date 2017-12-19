class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	sort(primes.begin(),primes.end());
    	int l = primes.size();
    	vector<int> idx(l,0);
    	vector<int> num(n,INT_MAX);
    	num[0] = 1;
    	for (int i=0;i<n;i++){
    		for (int j=0;j<l;j++)
    			num[i] = min(num[i],num[idx[j]]*primes[j]);
    		for (int j=0;j<l;j++)
    			if (num[i]==num[idx[j]]*primes[j])
    				idx[j]++;
    	}
        return num[n-1];
    }
};