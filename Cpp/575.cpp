/*
if diff>=all/2
	return all/2
else
	return diff
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
    	unordered_map<int,int> M;
    	for (auto c:candies)
    		M[c]++;
    	return M.size()>=candies.size()/2 ? candies.size()/2 : M.size();
    }
};
//Or define bitset<200001> v;
/*
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        bitset<200001> v;
        size_t cnt = 0;
        for (int i : candies) {
           cnt += !v.test(i + 100000);
           v.set(i + 100000);
        }
        return min(cnt, candies.size() / 2);
    }
};
*/