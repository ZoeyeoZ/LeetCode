class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    	if (k<0)
    		return 0;
        unordered_map<int,int> m;
        for (auto num:nums)
        	m[num]++;
        int ans = 0;
        for (auto p:m){
        	if ((k==0 && p.second>1)||(k&&m.count(p.first+k)))
        		ans++;
        }
        return ans;
    }
};