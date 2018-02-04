class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int k0 = 0, k1 = 0, num;
    	for (int k2 = 0; k2<nums.size(); k2++){
    		num = nums[k2];
    		nums[k2] = 2;
    		if (num<2){
    			nums[k1] = 1;
    			k1 ++;
    		}
    		if (num==0){
    			nums[k0] = 0;
    			k0 ++;
    		}
    	}
    }
};