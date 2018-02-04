class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int i=0,n=nums.size();
    	int ans = 1, id0 = -1;
    	for (;i<n;i++){
    		if (nums[i]==0){
    			if (id0!=-1)
    				return vector<int>(n,0);
    			else 
    				id0 = i;
    		}
    		else ans *=nums[i];
    	}
    	for (i=0;i<n;i++)
    		if (nums[i]==0)
    			nums[i] = ans;
    		else 	
    			nums[i] = id0==-1? ans/nums[i]:0;
    	return nums;
    }
};
/*
48ms

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(),1);
        
        for(size_t i = 1; i < nums.size();i++)
            result[i] = result[i - 1] * nums[i - 1];
        
        int right = 1;
        
        // right = right[ i + 1] * nums[ i + 1]
        for(int i = nums.size() - 2; i>=0;i--){
            result[i] = (right * nums[i + 1]) * result[i];
            right = right * nums[i + 1];
        }
        
        return result;
    }
};
*/