/*
DP
i=0..n-1, j=i-1..0
dp[j]=dp[i]+1, pre[i]=j,  if nums[j]%nums[i]==1

math
purning:
largest > num * 2^(difference in solution size to the best known solution size)
*/
class Solution {
public:
	vector<int> ans;
	int ansp = 0;
	int n, p, maxN;
	vector<int> nums, tmp, fur;
	bool check(int k, int i){
		if (p==0)
			return true;
		//longest subset including i
		if (p>fur[i] && k%tmp[p-1]==0){
			fur[i] = p;
			return true;
		}
		return false;
	}
	void helper(int id){
		for (int i=id; i<n; i++){
			//purning, no more valid number
			if (ansp>p && ((long)1<<(ansp-p))*nums[i]>maxN)
				break;
			// add nums[i] or not
			if (check(nums[i],i)){
				tmp[p++] = nums[i];
				helper(i+1);
				p--;
			}
		}
		if (ansp<p){
			ansp = p;
			ans = vector<int>(tmp.begin(),tmp.begin()+p);
		}
	}

    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	n = nums.size();
    	if (n<=1)
    		return nums;
    	sort(nums.begin(),nums.end());
    	this->nums = nums;
    	maxN = nums.back();
    	tmp = vector<int>(n);
    	fur = vector<int>(n);
    	helper(0);
    	return ans;     
    }
};