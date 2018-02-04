class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length()-1, l2 = b.length()-1;
        int c = 0;
        string ans = "";
        while (l1>=0||l2>=0||c>0){
        	c += l1>=0? a[l1--]-'0':0;
        	c += l2>=0? b[l2--]-'0':0;
        	ans = char(c%2+'0') + ans;
        	c = c/2;
        }
        return ans;
    }
};

/*
class Solution {
public:
    string addBinary(string a, string b) {
        string sol;
        int i = a.size()-1, j = b.size()-1;
        if(j > i) a.insert(a.begin(),(j-i),'0');
        else if(i > j) b.insert(b.begin(),(i-j),'0');    
        bool carry = false;
        i = a.size()-1; 
        while(i >= 0) {
            if(a[i] == b[i]) {
                sol.insert(sol.begin(),int(carry)+48);
                carry = (a[i] == '1');
            } else {
                sol.insert(sol.begin(),int(1-carry)+48);
            }     
            i--; 
        }
        if(carry) sol.insert(sol.begin(), '1');
        return sol;
    }
};
*/