class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int l = 0, len = nums.size(), r = len-1, m, x, y;
        while (l<=r){
            m = (l+r)/2;
            if (nums[m]<target)
                l = m +1;
            else r = m-1;
        }
        x = l;
    	l = 0, r = len -1;
        while (l<=r){
            m = (l+r)/2;
            if (nums[m]<target+1)
                l = m + 1;
            else r = m-1;
        }
        y = l-1;
        if ((ans[0] < nums.size())&&(nums[ans[0]]==target))
            return {x, y};
    	return {-1,-1};
        
    }
};