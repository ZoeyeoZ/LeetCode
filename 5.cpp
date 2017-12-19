// Longest Palindromic Substring
// select every as middle one, i--, j++ for the same one
class Solution{
public:
	string longestPalindrome(string s){
		if (s.length()< 2) 
			return s; 
		string ans;
		int i, j, l = s.length(), ml = 0, beg;
		for (int k = 0; k < l; k++){
			i = k;
			while ((i > 0 ) && (s[i-1] == s[k]))
				i --;
			j = k;
			while ((j < l-1) && (s[j+1] == s[k]))
				j ++;
			while ((i > 0) && (j < l-1) && (s[i-1] == s[j+1])){
				--i;
				++j;
			}
			if (j-i+1 > ml){
				ml = j-i+1; 
				beg = i;
			}

		}
		return s.substr(beg,ml);
	}
};