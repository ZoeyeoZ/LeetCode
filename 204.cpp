class Solution {
public:
    int countPrimes(int n) {
    	vector<bool> prime(n,true);
    	prime[0] = false;
    	prime[1] = false;
    	for (int i=2; i<sqrt(n); i++)
    		if (prime[i])
    			for (int j = i*i;j<n; j+=i)
    				prime[j] = false;
    	return count(prime.begin(), prime.end(), true);
        
    }
};
/*
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        bool notPrime[n];
        memset(notPrime, false, sizeof(notPrime));
        int count = n / 2;
        for (int i = 3; i * i < n; i += 2) {
          if (!notPrime[i]) {
            for (int j = i * i; j < n; j += 2 * i) {
              if (!notPrime[j]) {
                --count;
                notPrime[j] = true;
              }
            }
          }
        }
        return count;
    }
};
*/