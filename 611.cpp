/*
sort

i..j,k
triangle: 
	if ni+nj>nk,then all i+1..j-1 with j can be used, j-- to see the next [i,j-1]
				or i++ to see the next [i+1,j]

2,2,3,4
i=0, j=2, k=3 => ans+2, j=1 => i=1
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
    	int ans = 0, n = nums.size();
    	for (int k = n-1; k>1; k--){
    		int i = 0, j = k - 1;
    		while (i<j)
	    		if (nums[i]+nums[j]>nums[k])
	    			ans += j-i, j--;
	    		else
	    			i++;
    	}
    	return ans;
    }
};