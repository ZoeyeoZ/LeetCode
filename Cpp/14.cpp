//Longest Common Prefix
class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		if (strs.size()==0) return "";
		sort(strs.begin(), strs.end());
		int i= 0, l = strs.size()-1;
		while ((i < strs[0].length()) && (i < strs[l].length()) && (strs[0][i] == strs[l][i]))
			i++;
		return strs[0].substr(0,i);
	}
};