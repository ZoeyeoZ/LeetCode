class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if (nums.empty()) return 0;
		int k = 1;
		for (int i = 1;i<nums.size();i++)
			if (nums[i]!=nums[i-1])
				nums[k++] = nums[i];
		return k;
	}
};

/*
sample 22 ms submission
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int counts = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) counts++;
            else nums[i - counts] = nums[i];
        }
        return n - counts;
    }
};
*/