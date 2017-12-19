class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {  	
    	int n = nums.size();
    	if (n==0)
    		return {};
    	else if (n==1)
    		return {to_string(nums[0])};
    	vector<string> ans;
    	bool isF = true;
    	int i = 0, j = 0;
    	for (j=0;j<n;j++)
    		if (nums[j]!=nums[i]+(j-i)){
    			if (i==j-1)
    				ans.push_back(to_string(nums[i]));
    			else 
    				ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
    			i=j;
    			j--;
    		}
    	if (i==j-1)
    		ans.push_back(to_string(nums[i]));
    	else 
   			ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
   		return ans;
    }
};