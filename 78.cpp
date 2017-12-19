class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ans;
    	long n=1<<nums.size();
    	for (int i=0;i<n;i++){
    		int t = i, k=0;
    		vector<int> tmp;
    		while (t){
    			if (t&1==1)
    				tmp.push_back(nums[k]);
    			k++;
    			t >>= 1;
    		}
    		ans.push_back(tmp);
    	}
    	return ans;
    }
};