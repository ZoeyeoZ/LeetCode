class Solution {
public:
    string getHint(string secret, string guess) {
    	vector<int> num1(10,0),num2(10,0);
    	int l = secret.length();
    	int A = 0, B = 0;
    	for (int i=0;i<l;i++){
    		if (secret[i]==guess[i])
    			A++;
    		num1[secret[i]-'0']++;
    		num2[guess[i]-'0']++;
    	}
    	for (int i=0;i<10;i++)
    		B += min(num1[i],num2[i]);
    	return to_string(A)+"A"+to_string(B-A)+"B";
    }
};