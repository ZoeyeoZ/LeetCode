/*
1..9:9*1
10..99:90*2
100..999:900*3

n = n-9*1-90*2-..

eg. n = 190 -> 1, k=900->100+0;

n % d
*/
class Solution {
public:
    int findNthDigit(int n) {
    	if (n<=9)
    		return n;
    	long k = 9;
    	int w = 1;
    	while (n-k*w>=0){
    		n -= k*w;
    		k *= 10;
    		w++;
    	}
    	if (n==0)
    		return 9;
    	k = k/9 + (n-1)/w;
    	for (int i=(n+w-1)%w+1;i<w;i++)
    		k /= 10;
    	return k%10;
        
    }
};
//3ms
/*0
class Solution {
public:
    
    //wrong on case: 1000000000 => -48, should be 1
    int findNthDigit(int n) {
        long long m = 0, i = 0, j = 1, num;
        while (n > m){
            m += 9 * j * (i + 1);
            ++i;
            j *=10;
            
        }
        --i;
        j /= 10;
        m -= 9 * j * (i + 1);
        n -= m + 1;
        num = j  + n / (i + 1);
        string s = to_string(num);
        return s[n % (i + 1)] - '0';
    }
    */