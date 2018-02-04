/*
https://leetcode.com/problems/132-pattern/discuss/94071
n1<n3<n2
pair: n2>n3, n3>n1
From right->left, largest valid n3
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int n3 = INT_MIN, id = nums.size();
    	for (int i=nums.size()-1;i>=0;i--){
    		if (nums[i]<n3)//pair(n3>n1)
    			return true;
    		while (id<nums.size() && nums[i]>nums[id])//pair(n2>n3)
    			n3 = nums[id++];//largest valid n3
    		id--;
    		nums[id] = nums[i];//use rest of nums to store candidate n2
    	}
    	return false;
    }
};