// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int helper(int l,int r){//binary search
		if (l>r)
			return -1;
		int m = l+(r-l)/2;
		if (guess(m)==0)
			return m;
		else if (guess(m)==-1)
			return helper(l,m-1);
		else
			return helper(m+1,r);
	}
    int guessNumber(int n) {
        return helper(1,n);
    }
};