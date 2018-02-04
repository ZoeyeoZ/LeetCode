/*
no extra space & O(n) time
1. 
mark with highest bit
		int index = nums[i] & 0x7fffffff;
		if (nums[index - 1] < 0) {
			r.push_back(index);
		}
		else {
			nums[index - 1] |= 0x80000000;
		}
2.
mark using negative
		nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
3.
put x in nums[x-1] -> swap(nums[i], nums[nums[i]-1]);
then check if x doesn’t present in nums[x - 1], then x is absent.

we */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> ans;
    	for (auto num:nums){
    		if (nums[abs(num)-1]<0)
    			ans.push_back(abs(num));
    		else
    			nums[abs(num)-1] *= -1;
    	}
    	return ans;
    }
};
// We can caculate n = abs(n), then do the same thing, it will be faster
// But the problem is what if it appear 4 times?
