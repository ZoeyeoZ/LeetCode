class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
     	unordered_map<string,multiset<string>> airs;
     	vector<string> ans;
     	if (tickets.size()==0)
     		return ans;
     	for (auto t:tickets)
     		airs[t.first].insert(t.second);
     	stack<string> st;
     	st.push("JFK");
     	while (!st.empty()){
     		string cur = st.top();
     		if (airs[cur].empty()){
     			ans.push_back(cur);
     			st.pop();
     		}
     		else{
     			st.push(*(airs[cur].begin()));
     			airs[cur].erase(airs[cur].begin());
     		}
     	}
     	reverse(ans.begin(),ans.end());
     	return ans;
    }
};