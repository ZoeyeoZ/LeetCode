class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	int l = 0, r = numbers.size()-1;
    	int dif;
    	while (dif = numbers[l]+numbers[r] - target )
    		if (dif>0)
    			r--;
    		else l++;
    	return {l+1,r+1};
    }
};

