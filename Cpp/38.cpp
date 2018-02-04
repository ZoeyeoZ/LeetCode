class Solution {
public:
    string countAndSay(int n) {
    	return helper(n);
    }
    string helper(int n){
		string ans = "";
		if (n==1)
			return "1";
		else {
			string s = helper(--n);
			int i = 0, j;
			while (i<s.length()){
				j = i;
				while ((j<s.length())&&(s[j]==s[i]))
					j++;
				ans += to_string(j-i) + s[i];
				i = j;
			}
			return ans;
		}

	}
};