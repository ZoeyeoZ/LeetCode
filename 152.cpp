class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int l = nums.size();
    	if (l==0)
    		return 0;
    	int maxc = nums[0], minc = nums[0], tmp;
    	int ans = nums[0];
    	for(int i=1;i<l;i++)
    		if (nums[i]>0){
    			maxc = max(maxc*nums[i],nums[i]);
    			minc = min(minc*nums[i],nums[i]);
    			ans = max(ans,maxc);
    		}
    		else {
    			tmp = minc;
    			minc = min(maxc*nums[i],nums[i]);
    			maxc = max(tmp*nums[i],nums[i]);
    			ans = max(ans,maxc);
    		}
        return ans;
    }
};
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int contiguousMin = nums[0], contiguousMax = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = contiguousMax;
            contiguousMax = max(max(contiguousMax*nums[i], nums[i]), contiguousMin*nums[i]);
            contiguousMin = min(min(contiguousMin*nums[i], nums[i]), temp*nums[i]);
            res = max(res, contiguousMax);
        }
        
        return res;
    }
};*/
