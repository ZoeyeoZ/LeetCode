class Solution {
public:
    string multiply(string num1, string num2) {
    	int* a = new int[110];
    	int* b = new int[110];
    	for (int i=0; i<num1.length(); i++)
    		a[i] = num1[num1.length()-i-1]-48;
    	for (int i=0; i<num2.length(); i++)
    		b[i] = num2[num2.length()-i-1]-48;
    	int* c = new int[221];
    	for (int i=0; i<num1.length()+num2.length()+1; i++)
    		c[i] = 0;

        for (int i=0; i<num1.length(); i++)
        	for (int j=0; j<num2.length(); j++){
        		c[i+j] += a[i]*b[j];
        		c[i+j+1] += c[i+j]/10;
        		c[i+j] %=10;
        	}
        string ans="";
        int i = num1.length()+num2.length()+1;
        while ((c[i]==0)&&(i>0))
        	i--;
        i++;
        while (i--)
        	ans += char(c[i]+48);
        return ans;
    }
};

/*
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
    }
};*/
