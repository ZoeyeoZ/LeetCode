class Solution {
public:
    string convertToBase7(int num) {
    	if (num==0)
    		return "0";

    	string ans = "";
    	bool sig = true;
    	if (num<0)
    		sig = false, num = -1*num;

    	while (num>0) {
    		ans = to_string(num%7)+ans;
    		num /= 7;
    	}

    	return sig? ans:"-"+ans;
    }
};