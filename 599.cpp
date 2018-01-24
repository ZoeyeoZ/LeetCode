class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    	vector<string> ans;
    	unordered_map<string, int> M;
    	int len = INT_MAX;
    	for (int i = 0; i < list1.size(); i++)
    		M[list1[i]] = i;
    	for (int i = 0; i < list2.size(); i++)
    		if (M.count(list2[i]))
    			if (M[list2[i]]+i < len){
    				len = M[list2[i]]+i;
    				ans = {list2[i]};
    			}
    			else if (M[list2[i]]+i == len)
    				ans.push_back(list2[i]);
    	return ans;
    }
};