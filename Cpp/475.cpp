/*
sol1.
https://leetcode.com/problems/heaters/discuss/95875
while (heaters[i]+heaters[i+1]<=2x)

sol2.
caculate the minimal distance from left/right:
	find h's position in heaters[BFS]
find the maximum
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    	sort(heaters.begin(),heaters.end());
    	sort(houses.begin(),houses.end());
    	int ans = 0, i = 0;
    	for (auto h:houses){
    		while (i+1<heaters.size() && 2*h>=heaters[i]+heaters[i+1]) // i is the closest heater
    			i++;
    		ans = max(ans,abs(heaters[i]-h));
    	}
        return ans;
    }
};