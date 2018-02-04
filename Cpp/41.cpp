// must in [1..k]
// nums[i] store all nums && < 0 for storing i exists or not
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	if (nums.size()==0)
    		return 1;
    	int k = Turenums(nums);
    	int ans = k, num;
    	for (int i=0; i<k; i++){
    		num = abs(nums[i]);
    		if((num<=k)&&(nums[num-1]>0))
    			nums[num-1] *= -1;
    	}
    	for (int i=0; i<k; i++)
    		if (nums[i]>0){
    			ans = i;
    			break;
    		}
    	return ans+1;
    }
    int Turenums(vector<int>& nums){
    	int l = nums.size();
    	int k = 0;
    	for (int i=0;i<l;i++)
    		if (nums[i]>0){
    			if (i!=k){
					nums[i] ^= nums[k];
	    			nums[k] ^= nums[i];
	    			nums[i] ^= nums[k];	
    			}
    			k++;
    		}
    	return k;
    }
};

/*
misunderstand the problem
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int l = nums.size(), minN = INT_MAX, maxN = 0, s = 0;
    	for (int num:nums){
    		if (num<=0)
    			l--;
    		else{
    			s += num;
    			if (num>maxN)
    				maxN = num;
    			if (num<minN)
    				minN = num;
    		}
    	}
    	if ((minN+maxN)*l/2==s)
    		if (minN==1)
    			return maxN+1;
    		else return 1;
    	return (minN+maxN)*(l+1)/2-s;
        
    }
};
*/