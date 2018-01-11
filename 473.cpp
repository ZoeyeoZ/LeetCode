/*
sumL % 4 = 0
Ever matchsticks should be used
DFS

optimization1&2:
sort, long->short, less time
if (sidesLength[i] + matches[index] > target) continue;


i=0..3
if len[i]+nums[id]<=t
	len[i] += nums[id]
	dfs()
	len[i] -= nums[id]

optimization3:

*/
class Solution {
public:
	bool dfs(vector<int>& len, const vector<int>& nums, int id, const int t){
		if (id==nums.size())
			return len[0]==len[1] && len[1]==len[2] && len[2]==len[3];
		for (int i=0;i<4;i++){
			if (len[i]+nums[id]>t)
				continue;
			/*wrong
			int j = i;
			while (--j>=0)
				if (len[i]!=len[j])
					break; //if len[i]==len[j], means already checked same length before
			if (j!=-1)
				continue;
			*/
			//=>12ms
			int j = i-1;
            while (j >= 0 && sum[i] != sum[j])
               j--;
            if (j != -1) continue;
			
			len[i] += nums[id];
			if (dfs(len,nums,id+1,t))
				return true;
			len[i] -= nums[id];
		}
		return false;
	}
    bool makesquare(vector<int>& nums) {
    	if (nums.size()<4)
    		return false;
    	int sum = 0;
    	for (auto num:nums)
    		sum += num;
    	if (sum%4==!0 || nums[0]>sum/4)
    		return false;
    	sort(nums.rbegin(),nums.rend());
    	vector<int> len(4,0);
        return dfs(len,nums,0,sum/4);
    }
};