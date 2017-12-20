//greedy
class Solution {
public:
    string removeDuplicateLetters(string s) {
    	vector<int> chs(256,0);
    	vector<bool> visited(256,false);
    	for (char ch:s)
    		chs[ch]++;
    	string ans=" ";
    	for (char ch:s){
    		chs[ch]--;
    		if (visited[ch])
    			continue;
    		while (ch<ans.back() && chs[ans.back()]){
    			visited[ans.back()] = false;
    			ans.pop_back();
    		}
    		ans += ch;
    		visited[ch] = true;
    	}
    	return ans.substr(1);
    }
};