class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, len = nums.size(), r = len-1, m;
        // find smallest
        while (l<r){
            m = (l+r)/2;
            if (nums[m]>nums[r])
                l = m+1;
            else if (nums[m]<nums[r])
                r = m;
            else l++,r--;
        }
        return nums[l];
    }
};
