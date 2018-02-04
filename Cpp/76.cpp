class Solution {
public:
    string minWindow(string s, string t) {
    	if (s.empty()||t.empty())
    		return "";
    	vector<int> tchs(128,0);
    	vector<bool> tch(128,false);
    	for (char ch:t){
    		tchs[ch]++;
    		tch[ch] = true;
    	}
    	int l = 0, r = 0, cont = t.size(), minL = INT_MAX, minId = 0;
    	while (l<s.size() && r<=s.size()){
    		if (cont){
    			if ((tch[s[r]]) && (tchs[s[r]]>0))
    				cont --;
    			tchs[s[r]]--;
    			r++;
    		}
    		else{
    			if (minL>r-l){
    				minL = r-l;
    				minId = l;
    			}
    			tchs[s[l]]++;
    			if ((tch[s[l]]) && (tchs[s[l]]>0))
    				cont ++;
    			l++;
    		}
    	}
    	if (minL == INT_MAX)
    		return "";
    	return s.substr(minId,minL);



        
    }
};
/*
class Solution
{
 public:
  string minWindow(string s, string t)
  {
    vector<int> cnt(128, 0);
    for (char ch : t) ++cnt[ch];

    int left = t.size(), i0 = 0, len = s.size() + 1;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (--cnt[s[j]] >= 0) --left;
      for (; 0 == left; ++i) {
        if (j - i + 1 < len)
          i0 = i, len = j - i + 1;
        if (cnt[s[i]]++ == 0) ++left;
      }
    }

    return len > s.size() ? "" : s.substr(i0, len);
  }
};*/
