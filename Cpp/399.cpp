//Union-Find
class Solution {
private:	
	struct Node{
		Node* p;
		double v;
		Node():p(this),v(0.0){};
		Node(Node* pp, double vv) : p(pp), v(vv){};
		Node(double vv) : p(this),v(vv){};
	};
	unordered_map<string, Node*> map;
	void Union(Node* n1, Node* n2, double v){
		/*
		Vn1 = n1->v * V(n1->p)
		Vn2 = n2->v * V(n2->p)
		v = Vn1/Vn2 = [n1->v/n2->v] * [V(n1->p)/V(n2->p)]
		=>
		V(n1->p)/V(n2->p) = v * [n2->v/n1->v]

		Vn3 = n3->v * V(n3->p), n3->p = p1
			= n3->v * V(n1->p)
			= [n3->v * V(n2->p)] / [V(n2->p)/V(n1->p)]
			= [n3->v * V(n2->p)] * [V(n1->p)/V(n2->p)]
			= [n3->v * V(n2->p)] * [v * [n2->v/n1->v]]
		*/
		Node* p1 = Find(n1), *p2 = Find(n2);
		double k = (n2->v)*v/(n1->v);
		for (auto it=map.begin(); it!=map.end(); it++)
			if (Find(it->second) == p1){
				it->second->v *= k;
				it->second->p = p2;
			}
		p1 -> p = p2;
	}
	Node* Find(Node* node){
		if (node->p == node)
			return node;
		else
			return node->p = Find(node->p);
	}
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        for (int i=0;i<equations.size();i++){
        	string s1 = equations[i].first, s2 = equations[i].second;
        	if (map.count(s1)==0 && map.count(s2)==0){
        		map[s2] = new Node(1);
        		map[s1] = new Node(map[s2],values[i]);
        	}
        	else if (map.count(s1)==0){
        		map[s1] = new Node(map[s2],values[i]*map[s2]->v);
        	}
        	else if (map.count(s2)==0){
        		map[s2] = new Node(map[s1],map[s1]->v/values[i]);
        	}
        	else{
        		Union(map[s1],map[s2],values[i]);
        	}
        }
        for (auto q:queries){
        	string s1 = q.first, s2 = q.second;
        	if (map.count(s1)==0 || map.count(s2)==0 || Find(map[s1])!=Find(map[s2]))
        		ans.push_back(-1);
        	else {
        		ans.push_back(map[s1]->v / map[s2]->v);
        	}
        }
        return ans;
    }
};