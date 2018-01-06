//windoe:[i,j]
class Solution {
public:
    int characterReplacement(string s, int k) {
    	int i = 0, j = 0, l = s.length();
    	if (l<=k)
    		return l;
    	int ans = 0;
    	vector<int> ch(255,0);
    	while (j<l){
    		ch[s[j++]]++;
    		if (j-i - *max_element(ch.begin()+65, ch.begin()+91) > k)
            	ch[s[i++]]--;
    		ans = max(ans,j-i);
    	}
        return ans;
    }
};
//19
/*
6
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        vector<int> count(26);
        int start = 0, maxCount = 0, maxLength = 0;
        for (int end = 0; end < len; end++) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            while (end - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
*/
