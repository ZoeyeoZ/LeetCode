//i^i>>1
class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> ans;
    	int j = 1<<n;
    	for (int i=0;i<j;i++)
    		ans.push_back(i^i>>1);
    	return ans;
    }
};