//4Sum
class Solution{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target){
		sort(nums.begin(),nums.end());
		vector<vector<int>> ans;
		for (int k1=0; k1<nums.size();k1++){
			if ((k1>0)&&(nums[k1]==nums[k1-1]))
				continue;
			for (int k2=k1+1; k2<nums.size();k2++){
				if ((k2-k1>1)&&(nums[k2]==nums[k2-1]))
					continue;
				int s = target-nums[k1]-nums[k2];
				int i = k2+1, j = nums.size()-1;
				while (i<j){
					if (nums[i]+nums[j]>s)
						j--;
					else if (nums[i]+nums[j]<s)
						i++;
					else{
						vector<int> qua(4,0);
						qua[0] = nums[k1];
						qua[1] = nums[k2];
						qua[2] = nums[i];
						qua[3] = nums[j];
						ans.push_back(qua);
						while ((i<j) && (nums[i]==qua[2]))
							i++;
						while ((i<j) && (nums[j]==qua[3]))
							j--;
					}
				}
			}
		}
		return ans;
	}
};

//可以再加约束，
//例如nums[k1]+..+nums[k1+3]>t -> break;
//nums[k1]+nums[k2]+..+nums[k2+2]>t -> break;
