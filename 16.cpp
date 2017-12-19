//3Sum closest
class Solution{
public:
	int threeSumClosest(vector<int>& nums,int target){
		if (nums.size()==3)
			return nums[0]+nums[1]+nums[2];
		sort(nums.begin(),nums.end());
		int ans=INT_MAX,sum=0;
		for (int k=0; k<nums.size(); k++){
			if ((k>0)&&(nums[k]==nums[k-1]))
				continue;
			int s = target-nums[k];
			int i = k+1, j = nums.size()-1;
			while (i<j){
				if (abs(nums[i]+nums[j]-s) < ans){
					ans = abs(nums[i]+nums[j]-s);
					sum = nums[i]+nums[j]+nums[k];
				}
				if (nums[i]+nums[j]>s)
					j--;
				else if (nums[i]+nums[j]<s)
					i++;
				else
					return target;
			}
		}
		return sum;
	}
};