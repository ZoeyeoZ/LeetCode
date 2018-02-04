// ZigZag conversion
/* 
special for 1,2:
1: s
2: s[0],2,4 ... + s[1],3,5...

normal:
1			2n-1	
2	2n-2	
3	
.
.	2n-(n-1)
n

||
||
numRows = 1 : s
else:
	i = 1..n

	if numROw2 == 2,
		 k = 0 .. (ls-1)/numRows+1;
	else k = 0 .. (ls-1)/numRows/2+1;
	
	[i,2k] = k*(2n-2) + i
	[i,2k+1] = k*(2n-2) + 2n - i = (k+1)*(2n-2) - i + 2
class Solution {
public:
    string convert(string s, int numRows) {
		if ((numRows == 1)||(s.length() < numRows))
			return s;
		string ans = "";
		int ls = s.length(), l;
		if (numRows == 2)
			l = (ls-1)/numRows+1;
		else
			l = (ls-1)/numRows/2+1;
		int i = 1, n = 2 * numRows -2;
		for (int k = 0; k <= l; k++)
			if (k*n+i-1<ls)
			ans = ans+s[k*n+i-1];
        if (numRows>2){
            for (i = 2; i < numRows; i++)	
                for (int k = 0; k <= l; k++){
                    if (k*n+i-1 < ls)
                        ans = ans + s[k*n+i-1];
                    if ((k+1)*n-i+1 < ls)
                        ans = ans + s[(k+1)*n-i+1];
                }
        }
		i = numRows;
		for (int k = 0; k <= l; k++)
			if (k*n+i-1 < ls)
				ans = ans+s[k*n+i-1];

		return ans;      
    }
};
WRONG!
*/

class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows<=1)
    		return s;
    	int len = s.length();
    	vector<string> ans(numRows,"");
    	int row = 0, move = 1;
    	for (int i=0;i<len;i++){
    		ans[row] += s[i];
    		if (row==0)
    			move = 1;
    		else if (row==numRows-1)
    			move = -1;
    		row += move;
    	}
    	s.clear();
    	for (int i=0; i<numRows; i++)
    		s+=ans[i];
	    return s;
	}
};


/*
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= 1 || numRows <= 1) {
            return s;
        }
        
        string result(n, 'c');
        int periodic = (numRows - 1) << 1;
        
        int k = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += periodic) {
                result[k++] = s[j];
                if (i > 0 && i < numRows - 1) {
                    int partner = j + periodic - 2 * i;
                    if (partner < n) {
                        result[k++] = s[partner];
                    }
                }
            }
        }
        return result;
    }
};
*/