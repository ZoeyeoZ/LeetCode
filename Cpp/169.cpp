//since we can assume the majorith element must exist
//it's number must > others. every 2 elements's number can be counteract
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int ans = 0, count = 0;
    	for (int i=0;i<nums.size();i++)
    		if (count == 0){
    			count ++;
    			ans = nums[i];
    		}
    		else if (ans==nums[i])
    				count ++;
    			else count --;
        return ans;
    }
};