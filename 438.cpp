//window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> ans;
    	vector<int> ch1(26,0), ch2(26,0);
    	int l1 = s.length(), l2 = p.length();
    	if (l1<l2)
    		return ans;
    	for (int i=0; i<l2;i++){
    		ch1[s[i]-'a']++;
    		ch2[p[i]-'a']++;
    	}
    	if (ch1==ch2)
    		ans.push_back(0);
    	for (int i=l2;i<l1;i++){
    		ch1[s[i-l2]-'a']--;
    		ch1[s[i]-'a']++;
    		if (ch1==ch2)
    			ans.push_back(i-l2+1);
    	}
    	return ans;    
    }
};