//Generate Parentheses
class Solution{
public:
	vector<string> generateParenthesis(int n){
		vector<vector<string>> fn;
		vector<string> tmp = {""};
		fn.push_back(tmp);
		for (int i=1; i<=n; i++){
			tmp = {};
			for (int j=0; j<i; j++)
				for(string s1:fn[j])
					for (string s2:fn[i-1-j])
						tmp.push_back("("+s1+")"+s2);

			fn.push_back(tmp);
		}
		return fn[n];
	}
};