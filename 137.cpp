class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int show1 = 0, show2 = 0;
    	for (int num : nums){
    		show1 = (show1^num) & (~show2); //show 1 time, and not show in show2
    		show2 = (show2^num) & (~show1); //show 2 times
    	}
    	return show1;

	}

};