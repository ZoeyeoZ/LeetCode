class Solution {
private:
	vector<int> orignums, nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        this->orignums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums = orignums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for (int i = 0;i < n;i++) 
            swap(nums[i+rand()%(n-i)], nums[i]);
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */