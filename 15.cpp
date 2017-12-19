//3Sum
//The solution set must not contain duplicate triplets.
class Solution{
public:
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> ans;
		sort(nums.begin(),nums.end());
		for (int k=0; k < nums.size(); k++){
			if ((k>0)&&(nums[k]==nums[k-1]))
				continue;
			int s = -nums[k];
			int i = k+1, j = nums.size()-1;
			while (i<j){
				if (nums[i]+nums[j]>s)
					j--;
				else if (nums[i]+nums[j]<s)
					i++;
				else{
					vector<int> tri(3,0);
					tri[0] = nums[k];
					tri[1] = nums[i];
					tri[2] = nums[j];
					ans.push_back(tri);
					while ((i<j) && (nums[i]==tri[1]))
						i++;
					while ((i<j) && (nums[j]==tri[2]))
						j--;
				}
			}
		}
		return ans;
	}
};
