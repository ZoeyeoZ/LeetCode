//Reverse Integer
/*
! integer = 0
! reverse integer = begin with 0 -> move it
! reverse integer = overflow -> we can save as string, but this problem wants 0 -> save long int
*/
class Solution{
public:
	int reverse(int x){
		long ans = 0;
		while (x != 0 ){
			ans = ans*10 + x%10;
			x = x / 10;
			if ((ans > INT_MAX) || (ans < INT_MIN))
				return 0;
		}
		return (int) ans;
	}
};