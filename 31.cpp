class Solution {
public:
   	vector<int> nextPermutation(vector<int>& nums) {
   	//void nextPermutation(vector<int>& nums) {
    	int i = nums.size(), j, k, tmp;
    	while((i--) && (i>0) && (nums[i]<=nums[i-1])){}
    	cout << i<<endl;
    	if (i==0){
    		reverse(nums.begin(),nums.end());
    	}
    	else if (i==nums.size()-1){
    		j = i-1;
   			tmp  = nums[j];
    		nums[j] = nums[i];
    		nums[i] = tmp;
    	}
    	else{
	    	k = i-1, tmp = nums[k];
	    	while ((i<nums.size()-1)&&(nums[i+1]>nums[k]))
	    		i++;
	    	nums[k] = nums[i];
	    	nums[i] = tmp;
	    	j = nums.size()-1;
	    	i = k+1;
	    	while (j>i){
	    		tmp  = nums[j];
	    		nums[j] = nums[i];
	    		nums[i] = tmp;
	    		j--;
	    		i++;
	    	}
    	}
    	return nums;
    }
};