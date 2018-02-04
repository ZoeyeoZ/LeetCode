/*
the unordered_set<> does not support vector<int> to be the key default

use unordered_set<int> 
store the number used and avoid using the same number in the same loop

*/
class Solution {
public:
	void helper(vector<vector<int>>& ans, vector<int>& cur, int id, vector<int>& nums){
		if (cur.size()>1)
			ans.push_back(cur);
		unordered_set<int> used;
		for (int i = id; i<nums.size();i++)
			if ((cur.size()==0 || cur.back()<=nums[i]) && used.find(nums[i])==used.end()){
				cur.push_back(nums[i]);
				helper(ans,cur,i+1,nums);
				cur.pop_back();
				used.insert(nums[i]);
			}
	}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	vector<vector<int>> ans;
    	vector<int> cur;
    	helper(ans,cur,0,nums);
    	return ans;        
    }
};