/*
1.
Small half:    4 . 3 . 2 . 1 . 0 .
Large half:    . 9 . 8 . 7 . 6 . 5
----------------------------------
Together:      4 9 3 8 2 7 1 6 0 5
2.
find median => 3 parts: <,=,>
 re-map the indices
*/
/*
//there will be some nodes not visited...
//so we should use extra space to mark...p
class Solution {
public:
	int n;
	int next(int idx){
    	return (idx<n/2+n%2) ? (n/2-idx-1+n%2)*2: (n-idx)*2-1;
  	};
    void wiggleSort(vector<int>& nums) {
    	if (nums.size()==0)
    		return;
    	n = nums.size();
    	
    	sort(nums.begin(),nums.end());
    	int t=n;
    	int tmpn, tmpi,i=0, tmp= nums[i];
    	while (t--){
    		tmpi = next(i);
    		tmpn = nums[tmpi];
    		nums[tmpi] = tmp;
    		i = tmpi;
    		tmp = tmpn;
    	}
    }
};
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
	    sort(sorted.begin(), sorted.end());
	    for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
	        nums[i] = sorted[i%2==1 ? k++ : j++];
            //use i&1, reduce time:96->72
    }
};
