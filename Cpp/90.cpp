class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<vector<int>> ans = {{}};
    	sort(nums.begin(),nums.end());
    	int l = nums.size();
    	for (int i=0;i<l;i++){
    		int  cont = 0;
    		while ((i<l)&&nums[i]==nums[i+1]){
    			cont++;
    			i++;
    		}
    		int ansl = ans.size();
    		for (int j=0;j<ansl;j++){
    			vector<int> tmp = ans[j];
    			for (int k=0;k<=cont;k++){
    				tmp.push_back(nums[i]);
    				ans.push_back(tmp);
    			}

    		}
    	}
    	return ans;
    }
};