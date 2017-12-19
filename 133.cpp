/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodemap;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (!node)
    		return node;
    	if (!nodemap[node]){
    		nodemap[node] = new UndirectedGraphNode(node->label);
    		for (auto nei:node->neighbors)
    			nodemap[node]->neighbors.push_back(cloneGraph(nei));
    	}
    	return nodemap[node];        
    }
};