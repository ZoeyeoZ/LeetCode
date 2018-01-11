class Solution {
public:
    string complexNumberMultiply(string a, string b) {
    	char ch;
    	stringstream aa(a), bb(b), ans;
    	int a1,a2,b1,b2;
    	aa >> a1 >> ch >> a2 >> ch;
    	bb >> b1 >> ch >> b2 >> ch;
    	ans << a1*b1 - a2*b2 << "+" << a1*b2+a2*b1 << "i";
        return ans.str();
    }
};
/*
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int c,d,e,f;
        char ret[100];
        sscanf(a.c_str(),"%d+%di",&c,&d);
        sscanf(b.c_str(),"%d+%di",&e,&f);
        cout<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
        sprintf(ret,"%d+%di",(c*e-f*d),(d*e+c*f));
        string ans(ret);
        return ans;
    }
};
*/