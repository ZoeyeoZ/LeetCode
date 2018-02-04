class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int i=0;
    	for (auto n:nums)
    		if (n!=0)
    			nums[i++] = n;
    	for (;i<nums.size();i++)
    		nums[i] = 0;
    }
};
//16ms
/*
12ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i != j) {
                    swap(nums[i], nums[j++]);    
                } else {
                    j++;   
                }
            }
        }
    }
};
*/