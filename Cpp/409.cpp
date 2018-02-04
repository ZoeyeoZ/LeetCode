class Solution {
public:
    int longestPalindrome(string s) {
    	vector<int> cnt(255,0);
    	for (auto  ch:s)
    		cnt[ch]++;
    	int sumE = 0, hasO = 0;
    	for (int ch='a';ch<='z';ch++){
    		if (cnt[ch]%2==0)
    			sumE += cnt[ch];
    		else{
    			sumE += cnt[ch]-1;
    			hasO = 1;
    		}
    	}
    	for (int ch='A';ch<='Z';ch++){
    		if (cnt[ch]%2==0)
    			sumE += cnt[ch];
    		else{
    			sumE += cnt[ch]-1;
    			hasO = 1;
    		}
    	}
    	return sumE+hasO;
    }
};
//9
/*
3
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        bool mid = false;
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res += it->second;
            if (it->second % 2 == 1) {
                res -= 1;
                mid = true;
            }
        }
        
        return mid? res + 1 : res;
    }
};
*/