// Palindrome Number

// whether negative integer can be a palindorme? -> No
//ab..ded..ba | ab..deed..ba
//! a...0, eg. x = bcb0, rev = 0bc > b , 

class Solution{
public:
	bool isPalindrome(int x){
		if ((x<0)|| (x!=0 & x%10==0))
			return false;
		int m_rev = 0;
		while (m_rev < x){
			m_rev = m_rev * 10 + x % 10;
			x = x/10;
		}
		if (x == m_rev || x == m_rev/10)
			return true;
		return false;
	}
};