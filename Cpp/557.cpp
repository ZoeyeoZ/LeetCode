class Solution {
public:
    string reverseWords(string s) {
    	istringstream iss(s);
    	string w;
    	auto it = s.begin();
    	while (iss>>w){
    		it = copy(w.rbegin(),w.rend(),it);
    		it++;
    	}
        return s;
    }
};