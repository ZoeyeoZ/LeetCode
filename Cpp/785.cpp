//BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    	int n = graph.size();
    	vector<bool> visited(n, false);
    	vector<int> level(n, 0);
    	queue<int> q;
    	for (int i = 0; i < n; ++ i){
    		if (!visited[i]){
    			q.push(i);
    			visited[i] = true;
    			int u;
		    	while (!q.empty()){
		    		u = q.front();
		    		q.pop();
		    		for (int v : graph[u]){
		    			if (visited[v]){
		    				if (level[v] + level[u] != 1)
		    					return false;
		    			}
		    			else{
		    				visited[v] = true;
		    				level[v] = 1 - level[u];
		    				q.push(v);
		    			}
		    		}
		    	}
    		}
    	}
        return true;
    }
};