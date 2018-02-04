class Solution {
public:
    bool isPerfectSquare(int num) {
    	long i=0;
    	while (i*i<num)
    		i++;
        return i*i==num;
    }
};