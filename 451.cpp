class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int> chs;
    	for (char ch:s)
    		chs[ch]++;
    	vector<string> buck(s.size()+1,"");
    	for (auto ch:chs){
    		int n = ch.second;
    		buck[n].append(n,ch.first);
    	}
    	string ans = "";
    	for (int i=s.size();i>0;i--)
    		if (!buck[i].empty())
    			ans += buck[i];
    	return ans;
    }
};
//23
/*9
class Solution {
public:
    string frequencySort(string s)
    {
        string ans;
        pair<char, int> freq[256] = { {0, 0} };
        
        // Loop through the characters in string and store the character and frequency into the pair
        for (const auto &c : s) {
            freq[c].first = c;
            ++freq[c].second;
        }
        // Sort the pair based on frequency from previous loop 
        sort(begin(freq), end(freq),
            [](pair<char, int>& l, pair<char, int>& r) {
            return l.second > r.second;
        });
        // Append the pair into the string 
        for (auto i = begin(freq); i != end(freq); ++i)
            ans.append(i->second, i->first);
        return ans;
    }
};
*/