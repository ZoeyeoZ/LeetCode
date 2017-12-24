class Solution {
public:
    int getSum(int a, int b) {
    	int tmp;
    	while (b!=0){
    		tmp = a^b;//sum without carry
    		b = (a&b)<<1;//carry
    		a = tmp;
    	}
    	return a;
    }
};