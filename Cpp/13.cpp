// Roman to Integer
class Solution{
public:
	int toNum(char ch){
		switch (ch) {  
           	case 'I': return 1;  
           	case 'V': return 5;  
           	case 'X': return 10;  
            case 'L': return 50;  
	        case 'C': return 100;  
	        case 'D': return 500;  
	        case 'M': return 1000;  
        }
        return 0; 

	}
	int romanToInt(string s){
		int ans = 0;
		int ln = 0, cn = 0;
		for (int i=0; i < s.length(); i++){
			cn = toNum(s[i]);
			if (cn > ln)
				ans -= (2*ln);
			ans += cn;
			ln = cn;
		}
		return ans;
	}
};