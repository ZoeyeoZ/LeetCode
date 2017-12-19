class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int k = 0;
		for (int i = 0;i<nums.size();i++)
			if (nums[i]!=val)
				nums[k++] = nums[i];
		return k;      
    }
};

/*
sample 3 ms submission
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int w = 0;
        int r = 0;
        int n = nums.size();
        while( r < n ) {
            if( nums[ r ] == val ) {
                ++r;
            } else {
                if( w != r ) {
                    nums[ w ] = nums[ r ];
                }
                ++w;
                ++r;
            }
        }
        return w;
    }
};
*/