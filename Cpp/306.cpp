class Solution {
public:
	string add(string n1, string n2){
		string ans;
		int l1 = n1.size()-1, l2 = n2.size()-1;
		int carry = 0, sum = 0;
		while (l1>=0 || l2>=0){
			sum = carry+(l1>=0 ? n1[l1--]-'0':0)+(l2>=0 ? n2[l2--]-'0':0);
			ans = to_string(sum%10)+ans;
			carry = sum/10;
		}
		if (carry>0)
			ans = to_string(carry)+ans;
		return ans;
	}
	bool helper(string n1, string n2, string n){
		//invalid number
		if (n1.size()>1 && n1[0]=='0' || n2.size()>1 && n2[0]=='0')
			return false;

		string s = add(n1,n2);
		if (s==n)
			return true;
			//s is lager || n.sub!=s
		if (s.size()>=n.size() || s.compare(n.substr(0,s.length()))!=0)
			return false;
		else
			//n.sub==s
			return helper(n2,s,n.substr(s.length()));
	}
    bool isAdditiveNumber(string num) {
    	int l = num.length();
        for (int i=1;i<=l/2;i++)
        	for (int j=1;j<=(l-i)/2;j++)
        		if (helper(num.substr(0,i),num.substr(i,j),num.substr(i+j)))
        			return true;
        return false;
    }
};