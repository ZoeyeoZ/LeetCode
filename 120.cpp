class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if (triangle.empty())
    		return 0;
    	vector<int> ans(triangle[triangle.size()-1].size(),0);
    	ans[0] = triangle[0][0];
    	int minans=INT_MAX;
    	for (int i=1; i<triangle.size(); i++){
    		ans[i] = ans[i-1] + triangle[i][i];
    		for (int j=i-1;j>0;j--)
    			ans[j] = min(ans[j-1],ans[j])+triangle[i][j];
    		ans[0] = ans[0] + + triangle[i][0];
    	}        
    	for (int i:ans)
    		minans = min(minans,i);
    	return minans;
    }
};