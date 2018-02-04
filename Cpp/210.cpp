class Solution {
public:
	vector<int> ans;
	vector<bool> inans;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    	vector<unordered_set<int>> g(numCourses);
		vector<bool> visited(numCourses,false);
		for (int i=0;i<numCourses;i++)
			inans.push_back(false);
    	for (auto p:prerequisites)
    		g[p.second].insert(p.first);
    	for (int i=0;i<numCourses;i++)
    		if (!visited[i] && helper(i,g,visited))
    			return {};
    	reverse(ans.begin(),ans.end());
    	return ans;
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
    	if (!inans[i]){
    		ans.push_back(i);
    		inans[i] = true;
    	}
    	visited[i] = false;
    	return false;
    }
};

/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prereqPairs) {
        vector<int> prereqNums(numCourses, 0);
        vector< vector<int> > graph(numCourses, vector<int>()); //prereq -> lec graph

        // create incomings list and graph
        for(int i=0;i<prereqPairs.size();i++){
        	int lec = prereqPairs[i].first;
        	int pre = prereqPairs[i].second;
        	graph[pre].push_back(lec);
        	prereqNums[lec]++;
        }

        vector<int> lectureOrder;
        queue<int> q;

        // fill queue with zero prereqs
        for(int i=0;i<numCourses;i++)
        	if(prereqNums[i] == 0)
        		q.push(i);

        // while
        while(!q.empty()){
        	int lec = q.front();
        	q.pop();

        	lectureOrder.push_back(lec);
        	int m = graph[lec].size();
        	for(int i=0;i<m;i++){
        		int nextLec = graph[lec][i];
        		prereqNums[nextLec]--;
        		if(prereqNums[nextLec] == 0)
        			q.push(nextLec);
        	}
        }

        // are there any cycle ?
        if(lectureOrder.size() < numCourses)
        	return vector<int>();
        else
        	return lectureOrder;
    }
};
*/