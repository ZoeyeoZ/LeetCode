//Implement strStr()
//KMP
class Solution {
public:
  int strStr(string haystack, string needle) {
    int l1 = haystack.length(), l2 = needle.length();
    if (l2==0)
      return 0;
    vector<int> value = lps(needle);
    for (int i=0, j=0; i<l1;){
      if (haystack[i]==needle[j]){
        i++;j++;
        if (j==l2)
          return i-j;
      }
      else {
        if (i<l1){
          if (j!=0)
            j = value[j-1];
          else i++;
        }
      }
    }
    return -1;
  }
private:
  vector<int> lps(string needle){//longest prefixes and suffixes
    int len = needle.length();
    vector<int> value(len,0);
    for (int i=1, l=0; i<len;){
      if (needle[i]==needle[l])
        value[i++] = ++l;
      else 
        if (l!=0) l = value[l-1];//back to the last pattern
        else value[i++] = 0;
    }
    return value;
  };
};



/*
KMP
- http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
- http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
- partial match length:
  the largest length of same proper prefixes and proper suffixes:
  	"abab",proper prefixes: a,ab,aba, proper suffixes: b,ab,bab. So it gets value 2

char:  | a | b | a | b | a | b | c | a |
index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
value: | 0 | 0 | 1 | 2 | 3 | 4 | 0 | 1 |


1.
bacbababaabcbab
 |
 abababca
table[partial_match_length - 1] = 0, so no skip

2.
bacbababaabcbab
    |||||
    abababca
table[partial_match_length - 1] = 3,
so skip: partial_match_length - table[partial_match_length - 1] = 2

3.
// x denotes a skip
bacbababaabcbab
    xx|||
      abababca
table[partial_match_length - 1] = 1. 
so skip: partial_match_length - table[partial_match_length - 1] = 2

4.
// x denotes a skip

bacbababaabcbab
      xx|
        abababca
Now our pattern is longer than the remaining characters in the text, so we know there’s no match.
*/