class Solution {
public:
	vector<int> helper(string input, unordered_map<string,vector<int>>& dp){
		vector<int> ans;
		int l = input.length();
		for (int i=0;i<l;i++){
			char ch = input[i];
			if (ch=='+' || ch=='-' || ch=='*'){
				vector<int> a1,a2;
				string ss = input.substr(0,i);
				if (dp.find(ss) != dp.end())
					a1 = dp[ss];
				else
					a1 = helper(ss,dp);
				ss = input.substr(i+1);
				if (dp.find(ss) != dp.end())
					a2 = dp[ss];
				else
					a2 = helper(ss,dp);
				for (auto n1:a1)
					for (auto n2:a2)
						switch (ch){
							case '+':
								ans.push_back(n1+n2);
								break;
							case '-':
								ans.push_back(n1-n2);
								break;
							case '*':
								ans.push_back(n1*n2);
								break;

						}
			}
		}
		if (ans.empty())
			ans.push_back(stoi(input));
		dp[input] = ans;
		return ans;
	}
    vector<int> diffWaysToCompute(string input) {
    	unordered_map<string,vector<int>> dp;
    	return helper(input,dp);
    }
};

/*
0ms
class Solution {
public:
    map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string input) {
        vector<int> res, res1, res2;
        if(memo.count(input)) return memo[input];
        for(int i=0;i<input.size();i++){
            if(!isdigit(input[i])){
                res1 = diffWaysToCompute(input.substr(0, i));
                res2 = diffWaysToCompute(input.substr(i+1));
                for(auto &r1:res1){
                    for(auto &r2:res2){
                        if(input[i]=='+') res.push_back(r1+r2);
                        else if(input[i]=='-') res.push_back(r1-r2);
                        else res.push_back(r1*r2);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        memo[input]=res;
        return res;
    }
};

*/