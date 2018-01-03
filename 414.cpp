class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //num may== INT_MIN;
    	long max1 = INT_MIN-1, max2 = INT_MIN-1, max3 = INT_MIN-1;
    	for (int n:nums){
    		if (n==max1 || n==max2 || n==max3)
    			continue;
    		if (max1==INT_MIN-1 || n>max1){
    			max3 = max2;
    			max2 = max1;
    			max1 = n;
    		}
    		else if (max2==INT_MIN-1 || n>max2){
    			max3 = max2;
    			max2 = n;
    		} 
    		else if (max3==INT_MIN-1 || n>max3){
    			max3 = n;
    		} 
    	}
    	return max3==INT_MIN-1 ? max1:max3;
        
    }
};
//6ms;
//can let LONG_MIN->3ms...