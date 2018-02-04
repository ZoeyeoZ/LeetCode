// Longest Substring Without Repeating Characters
/* DP
ASCII,maintain an array, a[]=index
*/
class Solution{
public:
 	int lengthOfLongestSubstring(string s){
 		int ans = 0, beg = 1;
 		int a[256] = {};
 		for (int i = 0; i < s.length(); i++){
 			//for repeat letter, we should update begin index, since no repeat letter is allowed.
 			if (a[s[i]-0]+1 > beg)
 				beg = a[s[i]-0]+1;
 			a[s[i]-0] = i+1;
 			if ((i+1)-beg+1 >= ans)
 				ans = (i+1)-beg+1;
 		}
 		return ans;
	}
};