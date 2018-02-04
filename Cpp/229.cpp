//since we can assume the majorith element must exist
//it's number must > others. every 2 elements's number can be counteract
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
 
        vector<int> ans;
        if (nums.size()==0)        
            return ans;
        int cnt1 = 0, cnt2 = 0, ans1 = -1, ans2 = -1;
    	for (int i=0;i<nums.size();i++)
            if (ans1 == nums[i])
                cnt1++;
            else if (ans2 == nums[i])
                cnt2 ++;
    		else if (cnt1 == 0){
    			cnt1 ++;
    			ans1 = nums[i];
    		}
            else if (cnt2 == 0){
                cnt2 ++;
                ans2 = nums[i];
            }
            else {
                cnt1 --;
                cnt2 --;
            }
        // the above is the most 2 elements;
        
        cnt1 = cnt2 = 0;
        for (int num:nums)
            if (num == ans1)
                cnt1 ++;
            else if (num == ans2)
                cnt2 ++;
        
        if (cnt1>nums.size()/3)
            ans.push_back(ans1);
        if (cnt2>nums.size()/3)
            ans.push_back(ans2);
        return ans;
    }
};