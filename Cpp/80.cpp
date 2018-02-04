
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int l = nums.size();
    	if (l<=1)
    		return l;
    	int cont = 0;
    	for (int i=2; i<l; i++)
    		if (nums[i]==nums[i-2-cont])
    			cont ++;
    		else nums[i-cont] = nums[i];
    	return l-cont;
        
    }
};
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, len = nums.size();
        bool prev = false;
        if(len < 2)
            return len;
        count = 2;
        for(int i = 2 ; i <nums.size(); i++) {
            if(!((nums[i] == nums[count-1]) && (nums[i] == nums[count-2]))) {
                nums[count]= nums[i];
                count ++;
            }
        }
        return count;
    }
};
*/
