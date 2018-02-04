/*
If we num -> maximum, and we should be sure %(n-1)==0
(k+a*n)/(n-1) = m moves, k is sum(maximum - all nums ), a is num-maximum.

since after every add operation, minimum still be the minimum
=> minimum participate in every add operation
num = minimum + m moves

k = n*maximum - sum(nums)
a = num-maximum
m * (n-1) = k+a*n 
		  = n*maximum - sum(nums) + (num-maximum)*n
		  = (minimum + m)*n - sum(nums)
sum(nums) - minimun*n = m
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
    	int n = nums.size();
    	if (n<=1)
    		return 0;
    	int Min = INT_MAX;
    	long sum = 0;
    	for (int num:nums){
    		sum += num;
    		Min = min(Min,num);
    	}
        return sum-Min*n;
    }
};