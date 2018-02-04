class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    	int m = matrix.size();
    	if (m==0)
    		return 0;
    	int n = matrix[0].size();
    	int ans = INT_MIN;
    	for (int i = 0;i<m;i++){
    		vector<int> sums(n,0);
    		for (int j=i;j<m;j++){
    			for (int col=0;col<n;col++)
    				sums[col] += matrix[j][col];
    			set<int> tmps;
    			tmps.insert(0);
    			int curs = 0, curm = INT_MIN;
    			for (int sum:sums){
    				curs += sum;
    				auto it = tmps.lower_bound(curs-k);
    				if (it!=tmps.end())
    					curm = max(curm,curs-*it);
    				tmps.insert(curs);
    			}
    			ans = max(ans,curm);
    			if (ans==k)
    				return ans;
    		}
    	}
    	return ans;
    }
};
/*69ms
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int result = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> sum (n,0);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++)
                    sum[k] += matrix[k][j];
                
                vector<int> acSum;
                acSum.push_back(0);
                int currSum = 0;
                for (int num:sum) {
                    currSum += num;
                    
                    int pos = binarySearch(currSum-k,acSum);
                    if (pos < acSum.size()) 
                        result = max(result,currSum-acSum[pos]);
                        
                    
                    pos = binarySearch(currSum,acSum);
                    acSum.insert(acSum.begin()+pos,currSum);
                    
                }
            }
        }
        return result;
    }
    
    int binarySearch(int obj, vector<int> &acSum) {
        int low = 0, high = acSum.size()-1;
        if (acSum[high] < obj)
            return high+1;
        while (low < high) {
            int mid = low+(high-low)/2;
            if (acSum[mid] < obj)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};
*/