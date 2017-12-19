class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0, curmax = 0, nextmax = 0, count = 0;
        while (cur<nums.size()-1){
        	count ++;
        	for (;cur<=curmax;cur++){
        		nextmax = max(nextmax,cur+nums[cur]);
        		if (nextmax>=nums.size()-1)
        			return count;
        	}
        	curmax = nextmax;
        }
        return count;
        
    }
};