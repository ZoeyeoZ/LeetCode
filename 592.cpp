/*
begin with 0/1, read a/b
a1/b1 + a2/b2 = (a1b2+b1a2)/(b1b2)
*/
class Solution {
public:
    string fractionAddition(string expression) {
    	istringstream iss(expression);
    	char ch;
    	int a1 = 0, b1 = 1, a2, b2;
    	while (iss >> a2 >> ch >> b2){
    		a1 = a1 * b2 + b1 * a2;
    		b1 *= b2;
    		int g = abs(__gcd(a1,b1));
    		a1 /= g;
    		b1 /= g;
    	}
        return to_string(a1)+"/"+to_string(b1);
    }
};