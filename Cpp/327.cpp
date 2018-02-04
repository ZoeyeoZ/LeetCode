//merge
class Solution {
public:
    vector<int> nums;
    vector<long> sum;
    int len;
    int lower, upper;
    int helper(int l, int r){
        if (l+1>=r)
            return 0;
        int m = l+(r-l)/2;
        int ls = m, us = m;
        int cnt = helper(l,m)+helper(m,r);
        for (int i=l; i<m; i++){
        	while (ls<r && sum[ls]-sum[i]<lower)
        		ls++;
        	while (us<r && sum[us]-sum[i]<=upper)
        		us++;
        	cnt += us-ls;
        }
        //inplace_merge(first,mid,last) first mid last都是容器中的迭代器，也就是说将容器中区间[first,mid)与区间[mid+1,last)进行合并。
        inplace_merge(sum.begin()+l, sum.begin()+m, sum.begin()+r);
        return cnt;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->nums;
        this->lower = lower;
        this->upper = upper;
        len = nums.size();
        sum = vector<long>(len+1,0);
        for (int i=0;i<len;i++)
            sum[i+1] = sum[i]+nums[i];
        return helper(0,len+1);
        
        
    }
};