//Merge sort based solution
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/
class Solution {
public:
	int n;
	vector<int> ans;
	vector<int> idx;
	vector<int> nums;
	void helper(int l, int r){
		if (l>=r)
			return;
		int m = l+(r-l)/2;
		helper(l,m);
		helper(m+1,r);

		//merge row2 to row1
		int ll = l, rr = m+1, cnt = 0;
		vector<int> tmp;
		while (ll<=m || rr<=r){
			if (rr>r || (ll<=m && nums[idx[ll]]<=nums[idx[rr]])){
				tmp.push_back(idx[ll]);
				ans[idx[ll]] += cnt;
				ll++;
			}
			else{
				tmp.push_back(idx[rr]);
				cnt++;
				rr++;
			}
		}

		for (int i=0;i<tmp.size();i++)
			idx[l+i] = tmp[i];

	}
    vector<int> countSmaller(vector<int>& nums) {
    	n = nums.size();
    	ans = vector<int>(n,0);
    	idx = vector<int>(n,0);
    	this->nums = nums;
    	for (int i=0;i<n;i++)
    		idx[i] = i;
    	helper(0,n-1);
    	return ans;
    }
};
//33ms
/*
22ms
class Solution {
public:
    int getSum(vector<int> &BITtree, int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BITtree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    
    void update(vector<int> &BITtree, int val, int idx) {
        while (idx < (int)BITtree.size()) {
            BITtree[idx] += val;
            idx += idx & -idx;
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() < 1) return vector<int>();
        vector<int> res(nums.size());
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0; i < (int)nums.size(); ++i) 
            minVal = min(nums[i], minVal);
        for (int i = 0; i < (int)nums.size(); ++i) 
            nums[i] -= minVal - 1;
        for (int i = 0; i < (int)nums.size(); ++i)
            maxVal = max(nums[i], maxVal);
        vector<int> BIT(maxVal + 1, 0);
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            res[i] = getSum(BIT, nums[i] - 1);
            update(BIT, 1, nums[i]);
        }
        return res;
    }
};
*/
