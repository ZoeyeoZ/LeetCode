/*
1. If n is even, halve it.
2. If n=3 or n-1 has less 1’s than n+1, decrement n.
3. Otherwise, increment n.
=>
3/end with 01 -> decrease
*/
class Solution {
public:
    int integerReplacement(int n) {//-> long n
    	int cnt = 0;
    	while (n!=1){
    		if ((n&1)==0)
    			n >>= 1;
    		else if (n==3 || ((n>>1)&1)==0)
    			n--;
    		else n++;
    		cnt++;
    	}
        return cnt;
    }
};