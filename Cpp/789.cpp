// on the path || dis<= ->false
// target may < 0
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    	bool res = true;
    	int dis = abs(target[0]) + abs(target[1]);
    	for (auto g:ghosts){
    		if (abs(g[0]-target[0])+abs(g[1]-target[1])<=dis)
    			res = false;
    	}
    	return res;
    }
};