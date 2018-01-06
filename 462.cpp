/*
Math
num = middle number
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/94951

nums[i] > num, decrement (nums[i]-num)
nums[i] < num, increment (num-nums[i])
if it's sorted,
	sum(num-nums[1..i])+sum(nums[i+1..n]-num)
  = |num-nums[1..i]|+|num-nums[i+1..n]|
  >= |nums[n+1-i]-nums[i]|
  and =, if num in [nums[i],nums[i+1]]
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {   
    	sort(nums.begin(),nums.end());
    	int n = nums.size(), ans = 0;
    	for (int i=0;i<n/2;i++)
    		ans += nums[n-1-i]-nums[i];
    	return ans;
    }
};