/*
1. Longest Path
Randomly select a node x as the root, do a dfs/bfs to find the node y that has the longest distance from x.
Then y must be one of the endpoints on some longest path.
Let y the new root, and do another dfs/bfs. Find the node z that has the longest distance from y.

Now, the path from y to z is the longest one, and thus its middle point(s) is the answer

2. Tree DP
Let dp[i] be the height of the tree when the tree root is i.
Arbitrarily pick a node, say node 0, as the root, and do a dfs.
When we reach a node u, and let T be the subtree by removing all u's descendant (see the right figure below).
maintain a variable acc that keeps track of the length of the longest path in T with one endpoint being u.

dp[u] = max(height[u], acc)

3. similar to 1
run BFS from all leaves, and deleting achieved one -> so the rest are middle

*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	vector<int> ans;
    	if (n==1)
    		return {0};

    	vector<unordered_set<int>> adj(n);
    	for (auto edge:edges){
    		adj[edge.first].insert(edge.second);
    		adj[edge.second].insert(edge.first);
    	}
    	//add leaves
    	for (int i=0;i<n;i++)
    		if (adj[i].size()==1)
    			ans.push_back(i);
    	
    	//BFS
    	while (true){
    		vector<int> tmp;
    		for (int u:ans)
    			for (int v:adj[u]){
    				adj[v].erase(u);
    				if (adj[v].size()==1)
    					tmp.push_back(v);
    			}
    		if (tmp.empty())
    			return ans;
    		ans = tmp;

    	}
        
    }
};