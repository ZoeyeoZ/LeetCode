class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0, maxp = 0;
        while ((cur<nums.size()-1)&&(cur <= max(maxp,cur+nums[cur]))){
            maxp = max(maxp,cur+nums[cur]);
            if (cur < maxp)
                cur++;
            else 
                return false;
        }
        return true;
        
    }
};