class Solution {
public:
	vector<int> nums;
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int n = 0, ans = -1;
	    for(int i = 0 ; i < nums.size(); i++){
	        if(nums[i] == target){
	        	n++;
		        if (ans==-1 || rand()%n == 0)
		        	ans = i;// with prob 1/n to replace the previous index
	   	 	}
	    }
	    return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
//99
/*
78
class Solution {
vector<int> _nums;
public:
Solution(vector<int> nums) {
    _nums = nums;
}

int pick(int target) {
    int n = 0, ans = -1;
    for(int i = 0 ; i < _nums.size(); i++){
        if(_nums[i] != target) continue;
        if(n == 0){ans = i; n++;}
        else{
            n++;
            if(rand() % n == 0){ans = i;}// with prob 1/(n+1) to replace the previous index
        }
    }
    return ans;
}
};*/