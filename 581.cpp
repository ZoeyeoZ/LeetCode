/*Find the first&last descreasing
Find the max & min between them
if left>min, may be lefter have same number be ignored, left--
if right<max, .., right++
right - left - 1, since we cal 2 more

special case
1,3,2,2,2 -> 4
2,3,3,2,4 -> 3
2,1 -> 2
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	int left = 0, right = nums.size()-1, ans = 0, n = nums.size();
    	while (left <= right && nums[left] <= nums[left+1])
    		left ++;
    	while (left <= right && nums[right-1] <= nums[right])
    		right --;
    	if (left < right){
    		int minN = *min_element(nums.begin()+left,nums.begin()+right+1);
    		int maxN = *max_element(nums.begin()+left,nums.begin()+right+1);
    		while (left > 0 && nums[left-1] > minN)
    			left --;
    		while (right < n-1 && nums[right+1] < maxN)
    			right ++;
    		ans = right - left + 1;
    	}
    	return ans;
    }
};