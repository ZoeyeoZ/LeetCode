//https://leetcode.com/problems/poor-pigs/discuss/94266
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    	int t = minutesToTest/minutesToDie + 1;
    	//pow(t,ans)>=buckets
    	return (int)ceil(log(buckets)/log(t));
    }
};