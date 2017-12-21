/*
break n into (n / x) x's, then the product will be x^(n/x)
derivative => n * x^(n/x-2) * (1 - ln(x)).
when x=e, =>0
2<e<3
*/
class Solution {
public:
    int integerBreak(int n) {
    	switch(n){
    		case(2): return 1;
    		case(3): return 2;
    	}
    	switch(n%3){
    		case(0): return (int) pow(3,n/3);
    		case(1): return 2*2*(int)pow(3,(n-4)/3);
    		case(2): return 2*(int) pow(3,n/3);
    	}
    }
};