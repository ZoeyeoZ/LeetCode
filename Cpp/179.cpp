// 342,34,3; 342,34,1 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> Snums;
        for (int num:nums)
            Snums.push_back(to_string(num));
        sort(Snums.begin(),Snums.end(),[](string a, string b){ return a+b>b+a;});
        for (string Snum:Snums)
            ans += Snum;
        while (ans[0]=='0' && ans.length()>1)
            ans.erase(0,1);
        return ans;
    }
};