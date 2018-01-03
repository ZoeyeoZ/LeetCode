/*
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]
[7,0]
[7,0],[7,1]
[7,0],[6,1],[7,1]
[5.0],[7,0],[6,1],[7,1]
[5.0],[7,0],[5,2],[6,1],[7,1]
[5.0],[7,0],[5,2],[6,1],[4,4],[7,1]
since smaller height won't influence larger one,
we construct by height decreasing oder;
*/class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    	auto compare = [](const pair<int,int> p1, const pair<int,int> p2){
    		return p1.first>p2.first ||  p1.first==p2.first &&  p1.second<p2.second;
    	};
    	sort(people.begin(),people.end(),compare);
    	 vector<pair<int, int>> ans;
    	 for (auto p:people){
    	 	ans.insert(ans.begin()+p.second,p);
    	 }
        return ans;
    }
};