class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    	int i=0;
    	vector<vector<int>> ans;
    	vector<int> tmp(k,0);
    	while (i>=0){
    		tmp[i]++;
    		if (tmp[i]>n)
    			i--;
    		else if (i==k-1)
    			ans.push_back(tmp);
    		else{
    			i++;
    			tmp[i]=tmp[i-1];
    		}
    	}
    	return ans;        
    }
};