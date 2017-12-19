class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	vector<unordered_set<int>> g(numCourses);
		vector<bool> visited(numCourses,false);
    	for (auto p:prerequisites)
    		g[p.second].insert(p.first);
    	for (int i=0;i<numCourses;i++)
    		if (!visited[i] && helper(i,g,visited))
    			return false;
    	return true;
    }
    bool helper(int i,vector<unordered_set<int>> &g, vector<bool> &visited){//DFS find cycle
    	if (visited[i])
    		return true;
    	visited[i] = true;
    	for (int next:g[i])
    		if (visited[next])
    			return true;
    		else if (helper(next,g,visited))
    			return true;
    	visited[i] = false;
    	return false;
    }
};