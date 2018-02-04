class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int l = 0, r = nums.size()-1, m,cnt;
    	while (l<r){
    		m = l+(r-l)/2;
    		cnt = 0;
    		for (int n:nums)
    			if (n<=m)
    				cnt++;
    		if (cnt>m)
    			r = m;
    		else
    			l = m+1;
    	}
    	return l;
    }
};