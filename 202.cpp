//Using fact all numbers in [2, 6] are not happy (and all not happy numbers end on a cycle that hits this interval):
class Solution {
public:
    bool isHappy(int n) {
    	while (n>6){
    		int ans = 0;
    		while (n){
	            ans += (n%10)*(n%10);
	            n /= 10;
	        }
	        n = ans;
    	}
    	return n==1;
        
    }
};

/*
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            if( fast == 1 || next( fast ) == 1 )
                return true;
            slow = next( slow );
            fast = next( next( fast ) );
        }while( slow != fast );
        return false;
    }
    
    int next( int n ){
        int k = 0;
        while( n ){
            k += ( n % 10 ) * ( n % 10 );
            n /= 10;
        }
        return k;
    }
};
*/