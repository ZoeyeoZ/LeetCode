//Fenwick Tree

class NumArray {
public:
	vector<int> biTree;
	vector<int> nums;
	int n;
    NumArray(vector<int> nums) {
    	//create Tree
    	n = nums.size();
    	biTree = vector<int>(n+1,0);
    	for (int i=1;i<=nums.size();i++)
    		updateT(nums[i-1],i);
    	this->nums = nums;
    }
    
    void update(int i, int val) {
    	if (biTree.size()==1)
    		return;
    	updateT(val-nums[i],i+1);
    	nums[i] = val;
    }
    
    int sumRange(int i, int j) {
    	if (biTree.size()==1)
    		return 0;
    	return getSum(j)-getSum(i-1);
    }
    void updateT(int val, int p){
    	while (p<=n){
    		biTree[p] += val;
    		// next
    		p = p+(p&-p);
    	}
    }
    int getSum(int p){
    	p = p+1;
    	int sum = 0;
    	while(p>0){
            sum += biTree[p];
            // parents
            p = p-(p&-p);
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */